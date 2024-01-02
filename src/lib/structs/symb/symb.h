#include "../util.h"
typedef struct {
    char magic[4];            // Section magic. SYMB in ASCII.
    uint32_t size;            // Size of the SYMB section.
    uint32_t fileNameOffset;  // Offset to file name table.
    uint32_t soundTreeOffset; // Offset to Sound tree.
    uint32_t playerTreeOffset;// Offset to Player tree.
    uint32_t groupTreeOffset; // Offset to Group tree.
    uint32_t bankTreeOffset;  // Offset to Bank tree.
} brsar_symb_t;
//symb

bool _read_symb(FILE *file, brsar_symb_t *symb);
void _null_symb(brsar_symb_t *symb);
void symb_contents(brsar_symb_t* symb);
void _swap_symb(brsar_symb_t *symb);