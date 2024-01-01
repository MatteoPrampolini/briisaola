#include <iso646.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "lib/brsar.h"

void usage()
{
  fputs("\e[1;4mUsage:\e[0m briiscola [flags] <action> [options] input...\n", stderr);
  fputs("\n\e[1;4mFlags:\e[0m\n", stderr);
  fputs("\n\e[1;4mActions:\e[0m\n\t\e[1minfo\e[22m: prints file information\n\t\e[1mdump\e[22m: extract file into specified folder\n", stderr);
  fputs("\n\e[1;4mOptions:\e[0m\n\t\e[1m-o/--output\e[22m: specify the output file\n", stderr);
}

int main(int argc, char *argv[])
{
    if (argc <2)
    {
        usage();
        return 1;
    }
    char *action = argv[1];
    char *filename = argv[2];

    // Change it for RSAR magic string check
    // if (strstr(filename, ".brsar") == NULL && strstr(filename, ".BRSAR") == NULL)
    // {
    //     printf("The file must have the .brsar extension\n");
    //     return 2;
    // }

    //action to lowercase
    for (int i = 0; action[i]; i++)
    {
        action[i] = tolower(action[i]);
    }
    //help
    if (!strncmp(action, "help", 4) || !strncmp(action, "h", 1))
    {
        usage();
        return 0;
    }
    //analyze
    else if (!strcmp(action, "info") || !strncmp(action, "i", 1))
    {
        file_info(filename);
    }
    //dump
    else if (!strncmp(action, "dump", 4) || !strncmp(action, "d", 1))
    {
        // if(argc<4){
        //      printf("Incompleted command. Usage: briiscola.exe help\n");
        //      return 3;
        // }
        file_dump(filename);
    }
    //error
    else
    {
        fputs("\e[1;31mERROR\e[0m: Invalid action\n\n", stderr);
        usage();
        return 1;
    }

    return 0;
}
