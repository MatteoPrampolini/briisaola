#include "symb_string_tree.h"
//Implementation not needed for our use case? https://wiki.tockdom.com/wiki/BRSAR_(File_Format)

void _swap_tree(brsar_symb_string_tree_t *tree)
{
    tree->bitFlag=_swap16(tree->bitFlag);
    tree->flags=_swap16(tree->flags);
    tree->index=_swap32(tree->index);
    tree->leftIndex=_swap32(tree->leftIndex);
    tree->rightIndex=_swap32(tree->rightIndex);
    tree->stringIndex=_swap32(tree->stringIndex);
}
