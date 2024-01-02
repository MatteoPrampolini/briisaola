#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
uint16_t _swap16(uint16_t n);
uint32_t _swap32(uint32_t n);
bool _read_struct(FILE *file, void * strct,  long unsigned int struct_size);
