#include "info.h"

bool _read_info(FILE *file, size_t offset, info_t *info)
{
    return _read_struct(file, offset, info, 4);
    _read_dataref(file, offset + 8 * 1, &(info->soundDataRef));
    _read_dataref(file, offset + 8 * 2, &(info->soundbankRef));
    _read_dataref(file, offset + 8 * 3, &(info->playerInfoRef));
    _read_dataref(file, offset + 8 * 4, &(info->collectionRef));
    _read_dataref(file, offset + 8 * 5, &(info->groupRef));
    _read_dataref(file, offset + 8 * 6, &(info->soundCountRef));
}

void _null_info(info_t *info)
{
    if (!info)
    {
        fputs("\e[1;31merror\e[0m: info is null\n", stderr);
        exit(EXIT_FAILURE);
    }
}

void _swap_info(info_t *info)
{
    //info->size = _swap32(info->size);
    _swap_dataref(&(info->soundDataRef));
    _swap_dataref(&(info->soundbankRef));
    _swap_dataref(&(info->playerInfoRef));
    _swap_dataref(&(info->collectionRef));
    _swap_dataref(&(info->groupRef));
    _swap_dataref(&(info->soundCountRef));
}

void info_contents(info_t *info)
{     if (!info)
        return;
    fprintf(stderr,"\e[1;4mInfo:\e[0m\n");
    fprintf(stderr,"► Magic: %s\n", _is_info_magic(info) ? "valid" : "invalid");
    //fprintf(stderr,"► Size: %d\n",info->size);
    dataref_contents(&(info->soundDataRef),"Sound Data");
    dataref_contents(&(info->soundbankRef),"Sound Bank");
    dataref_contents(&(info->playerInfoRef),"Player Info");
    dataref_contents(&(info->collectionRef),"Collection");
    dataref_contents(&(info->groupRef),"Group");
    dataref_contents(&(info->soundCountRef),"Sound Count");
    fprintf(stderr,"--------------------------------------\n");
}

bool _is_info_magic(info_t *info)
{
    _null_info(info);
    return (!strncmp(info->magic, "INFO", 4));
}
