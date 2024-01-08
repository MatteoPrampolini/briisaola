#include <string.h>
#include "structs/header.h"
#include "structs/symb/symb.h"
#include "structs/symb/symb_file_name.h"
#include "structs/symb/symb_string_table.h"
#include "structs/info/info.h"
#include "structs/datatable.h"
void file_info(const char *filename);
void file_dump(const char *filename);
void free_misc_malloc(FILE *file, brsar_symb_file_name_t *filename_table,brsar_symb_string_t* string_table);
void free_datatable(brsar_datatable_t *soundDataTable);