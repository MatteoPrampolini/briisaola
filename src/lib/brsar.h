#include <string.h>
#include "structs/header.h"
#include "structs/symb/symb.h"
#include "structs/symb/symb_file_name.h"
#include "structs/symb/symb_string_table.h"

#include "structs/info/info.h"
void file_info(const char *filename);
void file_dump(const char *filename);
void not_today_memory_leak(FILE *file, brsar_symb_file_name_t *filename_table,brsar_symb_string_t* string_table);