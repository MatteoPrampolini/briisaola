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
        not_today_memory_leak(file, NULL);

        exit(EXIT_FAILURE);
    }
    // HEADER
    brsar_header_t header;
    bool is_big_endian_b = false;
    if (!_read_header(file, &header))
    {
        // Failed to read header
        fputs("\e[1;31mERROR\e[0m: Failed to read header\n", stderr);
        not_today_memory_leak(file, NULL);

        exit(EXIT_FAILURE);
    }

    is_big_endian_b = _is_big_endian(&header);
    if (is_big_endian_b)
    {
        _swap_header(&header);
    }
    header_contents(&header);

    // SYMB
    brsar_symb_t symb;
    if (!_read_symb(file, &symb))
    {
        // Failed to read symb
        fputs("\e[1;31mERROR\e[0m: Failed to read symb\n", stderr);
        not_today_memory_leak(file, NULL);
        exit(EXIT_FAILURE);
    }
    if (is_big_endian_b)
    {
        _swap_symb(&symb);
    }
    symb_contents(&symb);
    // SYMB FILENAME
    brsar_symb_file_name_t filename_table;
    if (!_read_filename_table(file, &filename_table, is_big_endian_b))
    {
        // Failed to read symb
        fputs("\e[1;31mERROR\e[0m: Failed to read symb\n", stderr);
        not_today_memory_leak(file, &filename_table);
        exit(EXIT_FAILURE);
    }
    if (is_big_endian_b)
    {
        _swap_filename_table(&filename_table, is_big_endian_b);
    }
    filename_table_contents(&filename_table);
    //printf("%x\n", filename_table.offsetToFileName[0]);
    // printf("%u\n",filename_table.offsetToFileName[1]);
    // printf("%u\n",filename_table.offsetToFileName[2]);
    info_t info;
    
    //it should be 6EB20
    //TODO FIND INFO ADDRESS
    //SYMB String Table*TreeNode[N]
    //printf("info is at offset: %x\n",0x40+0x1C+4+filename_table.numberOfEntries*4+8*);
    //  if (!_read_info(file,0x40+01C+ filename_table.numberOfEntries, &info))
    // {
    //     // Failed to read symb
    //     fputs("\e[1;31mERROR\e[0m: Failed to read info\n", stderr);
    //     not_today_memory_leak(file, &filename_table);
    //     exit(EXIT_FAILURE);
    // }
    // info_contents(&info);

    not_today_memory_leak(file, &filename_table);
}

void file_dump(const char *filename)
{
    // Implement the file dump logic
    printf("\e[1;32mINFO\e[0m: Dumping file %s...\n", filename);
}

void not_today_memory_leak(FILE *file, brsar_symb_file_name_t *filename_table)
{
    if (file)
    {
        fclose(file);
    }
    if (filename_table)
    {
        free(filename_table->offsetToFileName);
    }
}

// CORE FUNCTIONS

// Read the first 40 bytes of `file` and update `header`struct. Return 1 if successful.
