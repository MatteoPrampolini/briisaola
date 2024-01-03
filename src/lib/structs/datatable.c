#include "datatable.h"

bool _read_datatable(FILE *file,size_t offset, brsar_datatable_t *datatable, bool is_big_endian_b)
{   
     _read_struct(file,offset,datatable,4);
     size_t numbers_of_files= is_big_endian_b? _swap32(datatable->numberOfEntries):datatable->numberOfEntries;
    datatable->references=malloc(numbers_of_files * sizeof(dataref_t));
  
    fread(datatable->references,sizeof(dataref_t),numbers_of_files,file);
    bool good_read=datatable->numberOfEntries>0;
    
    return good_read;

}

void _null_datatable(brsar_datatable_t *datatable)
{        if (!datatable)
    {
        fputs("\e[1;31merror\e[0m: datatabke is null\n", stderr);
        exit(EXIT_FAILURE);
    }
}

void datatable_contents(brsar_datatable_t *datatable)
{
           if (!datatable)
        return;
    printf("\n////GENERIC DATA TABLE////\n");
    printf("Number of entries: %u\n",datatable->numberOfEntries);
    for(size_t i=0;i<datatable->numberOfEntries;i++){
        dataref_contents(&(datatable->references[i]));
    }
}
