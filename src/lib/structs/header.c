#include "header.h"
bool _read_header(FILE *file, brsar_header_t *header)
{   
    return _read_struct(file,0,header,46);
}
void _null_header(brsar_header_t *header)
{
    if (!header)
    {
        fputs("\e[1;31merror\e[0m: header is null\n", stderr);
        exit(EXIT_FAILURE);
    }
}
// Print brsar_header_t struct in a human readable format to standard output.
void header_contents(brsar_header_t *header)
{

    if (!header)
        return;
    fprintf(stderr,"\e[1;4mHeader:\e[0m\n");
    fprintf(stderr,"► Magic: %s\n", _is_rsar_magic(header) ? "valid" : "invalid");
    fprintf(stderr,"► Endianness: %s\n", _is_big_endian(header) ? "true" : "false");

    uint8_t byte1 = (header->version >> 8) & 0xFF;
    uint8_t byte2 = header->version & 0xFF;
    fprintf(stderr,"► Version: %02X %02X\n", byte1, byte2);
    fprintf(stderr,"► File length: %u\n", header->fileLength);
    fprintf(stderr,"► Number of sections: %u\n", header->numSections);
    fprintf(stderr,"► Offset to the SYMB section: %u\n", header->symbOffset);
    fprintf(stderr,"► Size of the SYMB section: %u\n", header->symbSize);
    fprintf(stderr,"► Offset to the INFO section: %u\n", header->infoOffset);
    fprintf(stderr,"► Size of the INFO section: %u\n", header->infoSize);
    fprintf(stderr,"► Offset to the FILE section: %u\n", header->fileOffset);
    fprintf(stderr,"► Size of the FILE section %u\n", header->fileSize);
    fprintf(stderr,"--------------------------------------\n");}

//  Swap `header`variables between big endian and little endian notation
void _swap_header(brsar_header_t *header)
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
bool _is_rsar_magic(brsar_header_t *header)
{
    _null_header(header);
    return (!strncmp(header->magic, "RSAR", 4));
}
bool _is_big_endian(brsar_header_t *header)
{
    _null_header(header);
    return header->bom == 0xFFFE;
}
