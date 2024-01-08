#pragma once
#include "util.h"

typedef struct {
    uint8_t referenceType;  //Reference type. (0 = Address, 1 = Offset).
    uint8_t dataType;       // Offset 0x01, Byte
    uint16_t reserved;      // Offset 0x02, UInt16
    uint32_t value;         // Offset 0x04, UInt32
} dataref_t;

bool _read_dataref(FILE *file,size_t offset, dataref_t *dataref);
void _null_dataref(dataref_t *dataref);
void _swap_dataref(dataref_t *dataref);
void dataref_contents(dataref_t* dataref, char* name);