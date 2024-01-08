#include "symb.h"
bool _read_symb(FILE *file, brsar_symb_t *symb)
{   
    return _read_struct(file,0x40,symb,28); //offset always at 0x40
}
//  Swap `symb`variables between big endian and little endian notation
void _swap_symb(brsar_symb_t *symb)
{
    if (!symb)
    {
        return;
    }
    symb->size=_swap32(symb->size);
    symb->fileNameOffset=_swap32(symb->fileNameOffset);
    symb->soundTreeOffset=_swap32(symb->soundTreeOffset);
    symb->playerTreeOffset=_swap32(symb->playerTreeOffset);
    symb->groupTreeOffset=_swap32(symb->groupTreeOffset);
    symb->bankTreeOffset=_swap32(symb->bankTreeOffset);

    
}
void _null_symb(brsar_symb_t *symb)
{
    if (!symb)
    {
        fputs("\e[1;31merror\e[0m: symb is null\n", stderr);
        exit(EXIT_FAILURE);
    }
}
// Print `symb` struct in a human readable format to standard output.
void symb_contents(brsar_symb_t *symb)
{
    if (!symb)
        return;
   fprintf(stderr,"\e[1;4mSymb:\e[0m\n", stderr);
   fprintf(stderr,"► Magic: %s\n",strncmp(symb->magic,"SYMB",4)?"invalid":"valid");
    //printf("Section magic: %c%c%c%c\n", symb->magic[0], symb->magic[1], symb->magic[2], symb->magic[3]);
   fprintf(stderr,"► Size of the SYMB section: %u\n", symb->size);
   fprintf(stderr,"► Offset to file name table: %u\n", symb->fileNameOffset);
   fprintf(stderr,"► Offset to Sound tree: %u\n", symb->soundTreeOffset);
   fprintf(stderr,"► Offset to Player tree: %u\n", symb->playerTreeOffset);
   fprintf(stderr,"► Offset to Group tree: %u\n", symb->groupTreeOffset);
   fprintf(stderr,"► Offset to Bank tree: %u\n", symb->bankTreeOffset);
   fprintf(stderr,"--------------------------------------\n");
}