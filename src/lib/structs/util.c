#include "util.h"
uint16_t _swap16(uint16_t n)
{
    return (n >> 8) | (n << 8);
}
uint32_t _swap32(uint32_t n)
{
    return ((n >> 24) & 0xFF) |    // move byte 3 to byte 0
           ((n << 8) & 0xFF0000) | // move byte 1 to byte 2
           ((n >> 8) & 0xFF00) |   // move byte 2 to byte 1
           ((n << 24) & 0xFF000000);
}

bool _read_struct(FILE *file,size_t file_offset, void *strct, long unsigned int struct_size)
{
   if (!file || !strct)
    {
        return false;
    }
    fseek(file,file_offset,SEEK_SET);
    // Read the struct from the file
    size_t bytes_read = fread(strct, struct_size, 1, file);

    // Check if the correct number of bytes were read
    if (bytes_read != 1)
    {
        return false; // Failed to read struct
    }

    return true;
}

void _swap_magic(char magic[4])
{
    if (magic == NULL) {
        return;
    }
        char temp = magic[0];
        magic[0] = magic[3];
        magic[3] = temp;

        temp = magic[1];
        magic[1] = magic[2];
        magic[2] = temp;
    
}
