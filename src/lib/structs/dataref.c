#include "dataref.h"

bool _read_dataref(FILE *file,size_t offset, dataref_t *dataref)
{
    return _read_struct(file,offset,dataref,8);
}

void _swap_dataref(dataref_t *dataref)
{
     dataref->reserved=_swap16(dataref->reserved);
     dataref->value=_swap32(dataref->value);
}

void dataref_contents(dataref_t *dataref, char* name )
{
            if (!dataref)
        return;
    fprintf(stderr,"\t\e[1;4m%s Dataref:\e[0m\n",name);
    fprintf(stderr,"\t► Reference type: %s\n",dataref->referenceType?"Offset":"Address");
    fprintf(stderr,"\t► Data type: %d\n",dataref->dataType);
    fprintf(stderr,"\t► Value: %x\n",dataref->value);
    
}

void _null_dataref(dataref_t *dataref)
{
        if (!dataref)
    {
        fputs("\e[1;31merror\e[0m: dataref is null\n", stderr);
        exit(EXIT_FAILURE);
    }
}