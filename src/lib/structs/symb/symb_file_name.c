#include "symb_file_name.h"

bool _read_filename_table(FILE *file, brsar_symb_file_name_t *filename_table,bool is_big_endian_b)
{
    _read_struct(file,0x40+0x1C,filename_table,4);
    size_t numbers_of_files= is_big_endian_b? _swap32(filename_table->numberOfEntries):filename_table->numberOfEntries;
    filename_table->offsetToFileName=malloc(numbers_of_files * sizeof(uint32_t));
  
    fread(filename_table->offsetToFileName,sizeof(uint32_t),numbers_of_files,file);
    bool good_read=filename_table->numberOfEntries>0;
    
    return good_read;
}

void _null_filename_table(brsar_symb_file_name_t *filename_table)
{
        if (!filename_table)
    {
        fputs("\e[1;31merror\e[0m: filename_table is null\n", stderr);
        exit(EXIT_FAILURE);
    }
}

void filename_table_contents(brsar_symb_file_name_t *filename_table)
{
        if (!filename_table)
        return;
    printf("\n////SYMB FILENAME TABLE////\n");
    printf("Number of entries: %u\n",filename_table->numberOfEntries);
}

void _swap_filename_table(brsar_symb_file_name_t *filename_table,bool is_big_endian_b)
{
    size_t numbers_of_files= is_big_endian_b? _swap32(filename_table->numberOfEntries):filename_table->numberOfEntries;

    filename_table->numberOfEntries=_swap32(filename_table->numberOfEntries);
   
    for(size_t i=0;i<numbers_of_files;i++){
        filename_table->offsetToFileName[i]=_swap32(filename_table->offsetToFileName[i]);
    }
}
