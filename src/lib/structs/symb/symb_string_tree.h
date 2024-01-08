#include "../util.h"
typedef struct {
    //PATRICIA tree (or radix tree)
    //https://stackoverflow.com/questions/14708134/what-is-the-difference-between-trie-and-radix-trie-data-structures
    uint16_t flags;         // Flags (0x01 = Leaf Node)
    uint16_t bitFlag;       // Bit flag. Meaning unknown.
    uint32_t leftIndex;     // Left Index.
    uint32_t rightIndex;    // Right Index.
    uint32_t stringIndex;   // String Index.
    uint32_t index;         // Index.
} brsar_symb_string_tree_t;
void _swap_tree(brsar_symb_string_tree_t *tree);