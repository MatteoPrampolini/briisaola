#include "../util.h"
#include "symb_string_tree.h"
typedef struct {
    int32_t rootIndex;  //Root Index.
    uint32_t numberOfEntries;  // Number of entries (N)
    brsar_symb_string_tree_t * treeNode; //TreeNode[N] entries.
} brsar_symb_string_t;
bool _read_string_table(FILE *file,size_t offset, brsar_symb_string_t *string_table, bool is_big_endian_b);
void _null_string_table(brsar_symb_string_t *string_table);
void string_table_contents(brsar_symb_string_t* string_table);
void _swap_string_table(brsar_symb_string_t *string_table, bool is_big_endian_b);