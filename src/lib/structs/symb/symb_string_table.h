#include "../util.h"
#include "symb_string_tree.h"
typedef struct {
    int32_t rootIndex;  //Root Index.
    uint32_t numberOfEntries;  // Number of entries (N)
    brsar_symb_string_tree_t * treeNode; //TreeNode[N] entries.
} brsar_symb_string_t;