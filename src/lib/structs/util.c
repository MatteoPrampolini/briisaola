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

bool _read_struct(FILE *file, void *strct, long unsigned int struct_size)
{
   if (!file || !strct)
    {
        return false;
    }
    // Read the struct from the file
    size_t bytes_read = fread(strct, struct_size, 1, file);

    // Check if the correct number of bytes were read
    if (bytes_read != 1)
    {
        return false; // Failed to read struct
    }

    return true;
}
