#include "util.h"
typedef struct {
    char    magic[4];      // File magic. "RSAR" in ASCII.
    uint16_t bom;          // Byte order mark (BOM): 0xFEFF is big endian.
    uint16_t version;      // Version of the file format.
    uint32_t fileLength;    // Length of the file.
    uint16_t headerLength;  // Length of the header (always 0x40).
    uint16_t numSections;   // Number of sections.
    uint32_t symbOffset;    // Offset to the SYMB section.
    uint32_t symbSize;      // Size of the SYMB section.
    uint32_t infoOffset;    // Offset to the INFO section.
    uint32_t infoSize;      // Size of the INFO section.
    uint32_t fileOffset;    // Offset to the FILE section.
    uint32_t fileSize;      // Size of the FILE section.
    // End of header
} brsar_header_t;
bool _read_header(FILE* file, brsar_header_t* header);
void _null_header(brsar_header_t *header);
void header_contents(brsar_header_t* header);
void _swap_header(brsar_header_t *header);
bool _is_rsar_magic(brsar_header_t* header);
bool _is_big_endian(brsar_header_t* header);