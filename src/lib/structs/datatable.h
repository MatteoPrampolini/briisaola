#include "util.h"
#include "dataref.h"
typedef struct {
    uint32_t numberOfEntries;  // Number of entries (N)
    dataref_t* references; //Offset to file name
} brsar_datatable_t;

bool _read_datatable(FILE *file,size_t offset, brsar_datatable_t *datatable,bool is_big_endian_b);
void _null_datatable(brsar_datatable_t *datatable);
void datatable_contents(brsar_datatable_t* datatable,char* name);
void _swap_datatable(brsar_datatable_t *datatable,bool is_big_endian_b);