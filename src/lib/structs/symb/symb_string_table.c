#include "symb_string_table.h"
//Implementation not needed for our use case? https://wiki.tockdom.com/wiki/BRSAR_(File_Format)

bool _read_string_table(FILE *file,size_t offset, brsar_symb_string_t *string_table,bool is_big_endian_b)
{
     _read_struct(file,offset,string_table,8);
    size_t numbers_of_files= is_big_endian_b? _swap32(string_table->numberOfEntries):string_table->numberOfEntries;

    string_table->treeNode=malloc(numbers_of_files * sizeof(14)); //size of treenode
    fread(string_table->treeNode,sizeof(14),numbers_of_files,file);
    bool good_read=string_table->numberOfEntries>0;
    
    return good_read;
}

void _null_string_table(brsar_symb_string_t *string_table)
{        if (!string_table)
    {
        fputs("\e[1;31merror\e[0m: string table is null\n", stderr);
        exit(EXIT_FAILURE);
    }
}

void string_table_contents(brsar_symb_string_t *string_table)
{
    fprintf(stderr,"\e[1;4mString Table:\e[0m\n");
    fprintf(stderr,"► Root index: %d\n",string_table->rootIndex);
    fprintf(stderr,"► Number of entries %d\n",string_table->numberOfEntries);
    fprintf(stderr,"--------------------------------------\n");

    //do not  print trenode
}

void _swap_string_table(brsar_symb_string_t *string_table, bool is_big_endian_b)
{
    size_t numbers_of_files= is_big_endian_b? _swap32(string_table->numberOfEntries):string_table->numberOfEntries;

    string_table->numberOfEntries=_swap32(string_table->numberOfEntries);
    string_table->rootIndex=_swap32(string_table->rootIndex); 
    for(size_t i=0;i<numbers_of_files;i++){
        if(!&(string_table->treeNode[i]))
        {_swap_tree(&(string_table->treeNode[i]));}
    }
}
