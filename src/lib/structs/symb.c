#include "symb.h"
bool _read_symb(FILE *file, brsar_symb_t *symb)
{   
    return _read_struct(file,symb,sizeof(*symb));
}
void _null_symb(brsar_symb_t *symb)
{
    if (!symb)
    {
        fputs("\e[1;31merror\e[0m: symb is null\n", stderr);
        exit(EXIT_FAILURE);
    }
}
// Print brsar_symb_t struct in a human readable format to standard output.
void symb_contents(brsar_symb_t *symb)
{

    if (!symb)
        return;
    printf("\n////SYMB////\n");
    

    // uint8_t byte1 = (symb->version >> 8) & 0xFF;
    // uint8_t byte2 = symb->version & 0xFF;
    // printf("Version: %02X %02X\n", byte1, byte2);
    // printf("File length: %u\n", symb->fileLength);
    // printf("Number of sections: %u\n", symb->numSections);
    // printf("Offset to the SYMB section: %u\n", symb->symbOffset);
    // printf("Size of the SYMB section: %u\n", symb->symbSize);
    // printf("Offset to the INFO section: %u\n", symb->infoOffset);
    // printf("Size of the INFO section: %u\n", symb->infoSize);
    // printf("Offset to the FILE section: %u\n", symb->fileOffset);
    // printf("Size of the FILE section %u\n", symb->fileSize);
}

