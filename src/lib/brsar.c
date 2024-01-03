#include "brsar.h"


// MAIN FUNCTIONS
void file_info(const char *filename)
{
    printf("\e[1;32mINFO\e[0m: Analyzing file %s...\n", filename);
    FILE *file;
    file = fopen(filename, "rb");
    if (!file)
    {
        fprintf(stderr, "\e[1;31mERROR\e[0m: %s doesn't exist.\n", filename);
        exit(EXIT_FAILURE);
    }
    //HEADER
    brsar_header_t header;
    bool is_big_endian_b=false;
    if (_read_header(file, &header))
    {   
        is_big_endian_b=_is_big_endian(&header);
        if (is_big_endian_b)
        {
            _swap_header(&header);
        }
        header_contents(&header);
    }
    else
    {
        // Failed to read header
        fputs("\e[1;31mERROR\e[0m: Failed to read header\n", stderr);
        exit(EXIT_FAILURE);
    }
    //SYMB
    brsar_symb_t symb;
        if (_read_symb(file,&symb))
    {
        if (is_big_endian_b)
        {
        _swap_symb(&symb);
        }
        symb_contents(&symb);
    }
    else
    {
        // Failed to read symb
        fputs("\e[1;31mERROR\e[0m: Failed to read symb\n", stderr);
        exit(EXIT_FAILURE);
    }
    //SYMB FILENAME
        brsar_symb_file_name_t filename_table;
        if (_read_filename_table(file,&filename_table,is_big_endian_b))
    {
        if (is_big_endian_b)
        {
        _swap_filename_table(&filename_table,is_big_endian_b);
        }
        filename_table_contents(&filename_table);
        printf("%x\n",filename_table.offsetToFileName[0]);
        // printf("%u\n",filename_table.offsetToFileName[1]);
        // printf("%u\n",filename_table.offsetToFileName[2]);
        free(filename_table.offsetToFileName);
    }
    else
    {
        // Failed to read symb
        fputs("\e[1;31mERROR\e[0m: Failed to read symb\n", stderr);
        exit(EXIT_FAILURE);
    }
    

    fclose(file);
}

void file_dump(const char *filename)
{
    // Implement the file dump logic
    printf("\e[1;32mINFO\e[0m: Dumping file %s...\n", filename);
}

// CORE FUNCTIONS



// Read the first 40 bytes of `file` and update `header`struct. Return 1 if successful.

