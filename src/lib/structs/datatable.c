#include "datatable.h"

bool _read_datatable(FILE *file, size_t offset, brsar_datatable_t *datatable, bool is_big_endian_b)
{
    _read_struct(file, offset, datatable, 4);
    size_t numbers_of_files = is_big_endian_b ? _swap32(datatable->numberOfEntries) : datatable->numberOfEntries;
    datatable->references = malloc(numbers_of_files * sizeof(dataref_t));

    fread(datatable->references, sizeof(dataref_t), numbers_of_files, file);
    bool good_read = datatable->numberOfEntries > 0;
    return good_read;
}

void _null_datatable(brsar_datatable_t *datatable)
{
    if (!datatable)
    {
        fputs("\e[1;31merror\e[0m: datatabke is null\n", stderr);
        exit(EXIT_FAILURE);
    }
}

void datatable_contents(brsar_datatable_t *datatable,char* name)
{
    // TODO
    if (!datatable)
        return;
    fprintf(stderr,"\e[1;4m%s Datatable:\e[0m\n",name);
    fprintf(stderr,"► Number of entries: %u\n", datatable->numberOfEntries);
    for (size_t i = 0; i < datatable->numberOfEntries; i++)
    {
        dataref_contents(&(datatable->references[i]), "UNKNOWN");
        if(i==10){
         fprintf(stderr,"Subsequent %d entries are omitted from printing...\n", datatable->numberOfEntries-10); 
         break;  
        }
    }
}

void _swap_datatable(brsar_datatable_t *datatable, bool is_big_endian_b)
{
     size_t numbers_of_files= is_big_endian_b? _swap32(datatable->numberOfEntries):datatable->numberOfEntries;
    datatable->numberOfEntries=numbers_of_files;
    if(datatable->numberOfEntries>99999){printf("NO WAY THERE ARE MORE THAN 99999 ENTRIES.\n"); exit(EXIT_FAILURE);}
    for (size_t i = 0; i < datatable->numberOfEntries; i++)
    {
        _swap_dataref(&(datatable->references[i]));
    }
       
}
