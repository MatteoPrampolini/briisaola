#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
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
} Header;
uint16_t _swap16(uint16_t n);
uint32_t _swap32(uint32_t n);
void _swap_header(Header *header);
bool _is_BRSAR_magic(Header* header);
bool _is_big_endian(Header* header);
void analyzeFile(const char *filename);
void dumpFile(const char *filename);
int _read_header(FILE* file, Header* header);
void _header_to_string(Header* header);
