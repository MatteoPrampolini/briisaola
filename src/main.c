#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "lib/brsar.h"

void print_usage(){
    printf("INFO: Prints file information to screen\n syntax: briiscola.exe <filename.brsar> INFO\n");
    printf("DUMP: Extract file into specified folder\n syntax: briiscola.exe <filename.brsar> DUMP OUTPUT <folder_name>\n");
}
int main(int argc, char *argv[])
{
    if (argc <2)
    {
        printf("Usage: %s <file.brsar> <info/dump>\n", argv[0]);
        return 1;
    }
    char *filename = argv[1];
    char *option = argv[2];

    if (strstr(filename, ".brsar") == NULL && strstr(filename, ".BRSAR") == NULL)
    {
        printf("The file must have the .brsar extension\n");
        return 2;
    }
    //option to lowercase
    for (int i = 0; option[i]; i++)
    {
        option[i] = tolower(option[i]);
    }
    //help
    if (strcmp(option, "help") ==0 || strcmp(option, "h") ==0){
       print_usage();
    }
    //analyze
    else if (strcmp(option, "info") ==0 || strcmp(option, "i") ==0)
    {
        analyzeFile(filename);
    }
    //dump
    else if (strcmp(option, "dump") == 0)
    {
        if(argc<4){
             printf("Incompleted command. Usage: briiscola.exe help\n");
             return 3;
        }
        dumpFile(filename);
    }
    //error
    else
    {
        printf("Invalid option. Usage: %s help\n", argv[0]);
        return 4;
    }

    return 0;
}
