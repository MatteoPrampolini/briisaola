#include "../util.h"
#include "../dataref.h"
typedef struct {
    char magic[4];       // Offset 0x00, String (4 bytes)
    uint32_t sizeOfInfoSection; // Offset 0x04, UInt32
     dataref_t soundDataTable;       // Offset 0x08, Reference to Sound Data Table
     dataref_t soundbankTable;       // Offset 0x10, Reference to Soundbank Table
     dataref_t playerInfoTable;      // Offset 0x18, Reference to Player Info Table
     dataref_t collectionTable;      // Offset 0x20, Reference to Collection Table
     dataref_t groupTable;           // Offset 0x28, Reference to Group Table
     dataref_t soundCountTable;      // Offset 0x30, Reference to Sound Count Table

} info_t ;

bool _read_info(FILE *file,size_t offset, info_t *info);
void _null_info(info_t *info);
void _swap_info(info_t *info);
void info_contents(info_t* info);