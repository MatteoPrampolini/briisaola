#include "info.h"

bool _read_info(FILE *file, size_t offset, info_t *info)
{
    return _read_struct(file,offset,info,8);
    _read_dataref(file,offset,&(info->soundDataTable));
}
