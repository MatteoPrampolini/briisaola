#include "brsar.h"
#include <stdlib.h>

//MAIN FUNCTIONS
void analyzeFile(const char *filename)
{
    printf("Analyzing file %s...\n", filename);
    FILE *file;
    file = fopen(filename, "rb");
    if (!file)
    {
        printf("Error: %s doesn't exist.\n", filename);
        exit(EXIT_FAILURE);
    }

    Header header;
    if (_read_header(file, &header))
    {
        if (_is_big_endian(&header))
        {
            _swap_header(&header);
        }
        _header_to_string(&header);
    }
    else
    {
        // Failed to read header
        printf("Error: Failed to read header\n");
        exit(EXIT_FAILURE);
    }

    fclose(file);
}

void dumpFile(const char *filename)
{
    // Implement the file dump logic
    printf("Dumping file %s...\n", filename);
}


//CORE FUNCTIONS
// Swap `header`variables between big endian and little endian notation
void _swap_header(Header *header)
{
    if (!header)
    {
        return;
    }
    header->version = _swap16(header->version);
    header->fileLength = _swap32(header->fileLength);
    header->numSections = _swap16(header->numSections);
    header->symbOffset = _swap32(header->symbOffset);
    header->symbSize = _swap32(header->symbSize);
    header->infoOffset = _swap32(header->infoOffset);
    header->infoSize = _swap32(header->infoSize);
    header->fileOffset = _swap32(header->fileOffset);
    header->fileSize = _swap32(header->fileSize);
}
// Print Header struct in a human readable format to standard output.
void _header_to_string(Header *header)
{

    if (!header)
        return;
    printf("\n////HEADER////\n");
    printf("magic: %s\n", _is_BRSAR_magic(header) ? "valid" : "invalid");
    printf("big endian: %s\n", _is_big_endian(header) ? "true" : "false");
 
    uint8_t byte1 = (header->version >> 8) & 0xFF;
    uint8_t byte2 = header->version & 0xFF;
    printf("version: %02X %02X\n", byte1, byte2);
    printf("file lenght: %u\n", header->fileLength);
    printf("Number of sections: %u\n", header->numSections);
    printf("Offset to the SYMB section: %u\n", header->symbOffset);
    printf("Size of the SYMB section: %u\n", header->symbSize);
    printf("Offset to the INFO section: %u\n", header->infoOffset);
    printf("Size of the INFO section: %u\n", header->infoSize);
    printf("Offset to the FILE section: %u\n", header->fileOffset);
    printf("Size of the FILE section %u\n", header->fileSize);
}
// Read the first 40 bytes of `file` and update `header`struct. Return 1 if successful.
int _read_header(FILE *file, Header *header)
{
    if (file == NULL || header == NULL)
    {
        return 0;
    }
    // Read the header from the file
    size_t bytesRead = fread(header, sizeof(Header), 1, file);

    // Check if the correct number of bytes were read
    if (bytesRead != 1)
    {
        return 0; // Failed to read the header
    }
    if (_is_big_endian(header))
    {
    }
    return 1;
}

//UTILS FUNCTIONS
bool _is_BRSAR_magic(Header *header)
{
    if (!header)
    {
        printf("Error: header is NULL\n");
        exit(EXIT_FAILURE);
    }
    return (header->magic[0] == 'R' && header->magic[1] == 'S' && header->magic[2] == 'A' && header->magic[3] == 'R') ||
           (header->magic[3] == 'R' && header->magic[2] == 'S' && header->magic[1] == 'A' && header->magic[0] == 'R');
}
bool _is_big_endian(Header *header)
{
    if (!header)
    {
        printf("Error: header is NULL\n");
        exit(EXIT_FAILURE);
    }
    return header->bom == 0xFFFE;
}
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