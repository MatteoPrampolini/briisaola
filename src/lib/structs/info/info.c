#include "info.h"

bool _read_info(FILE *file, size_t offset, info_t *info)
{
    return _read_struct(file, offset, info, 8);
    _read_dataref(file, offset + 8 * 1, &(info->soundDataTable));
    _read_dataref(file, offset + 8 * 2, &(info->soundbankTable));
    _read_dataref(file, offset + 8 * 3, &(info->playerInfoTable));
    _read_dataref(file, offset + 8 * 4, &(info->collectionTable));
    _read_dataref(file, offset + 8 * 5, &(info->groupTable));
    _read_dataref(file, offset + 8 * 6, &(info->soundCountTable));
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
    info->size = _swap32(info->size);
    _swap_dataref(&(info->soundDataTable));
    _swap_dataref(&(info->soundbankTable));
    _swap_dataref(&(info->playerInfoTable));
    _swap_dataref(&(info->collectionTable));
    _swap_dataref(&(info->groupTable));
    _swap_dataref(&(info->soundCountTable));
}

void info_contents(info_t *info)
{     if (!info)
        return;
    fprintf(stderr,"\e[1;4mInfo:\e[0m\n");
    fprintf(stderr,"► Magic: %s\n", _is_info_magic(info) ? "valid" : "invalid");
    fprintf(stderr,"► Size: %d\n",info->size);
    dataref_contents(&(info->soundDataTable),"Sound Data");
    dataref_contents(&(info->soundbankTable),"Sound Bank");
    dataref_contents(&(info->playerInfoTable),"Player Info");
    dataref_contents(&(info->collectionTable),"Collection");
    dataref_contents(&(info->groupTable),"Group");
    dataref_contents(&(info->soundCountTable),"Sound Count");
    fprintf(stderr,"--------------------------------------\n");
}

bool _is_info_magic(info_t *info)
{
    _null_info(info);
    return (!strncmp(info->magic, "INFO", 4));
}
