#include "../util.h"
typedef struct {
    uint32_t numberOfEntries;  // Number of entries (N)
     uint32_t *offsetToFileName; //Offset to file name
} brsar_symb_file_name_t;

bool _read_filename_table(FILE *file, brsar_symb_file_name_t *filename_table,bool is_big_endian_b);
void _null_filename_table(brsar_symb_file_name_t *filename_table);
void filename_table_contents(brsar_symb_file_name_t* filename_table);
void _swap_filename_table(brsar_symb_file_name_t *filename_table,bool is_big_endian_b);