#include "brsar.h"
#include <stdlib.h>
bool isBRSAR(FILE* file ){
    if(!file){
        printf("Cannot read BRSAR file");
        exit(EXIT_FAILURE);
    }
    fseek(file,0,SEEK_SET);

    char magic[5];
    fgets(magic,5,file);
    return strcmp(magic,"RSAR")==0;

    
}
void analyzeFile(const char *filename) {
    printf("Analyzing file %s...\n", filename);
    FILE *file;
    file = fopen(filename,"rb");
    if(!file){
        printf("Error: %s doesn't exist.\n",filename);
        exit(EXIT_FAILURE);

    }
    printf("%s magic: %s",filename,isBRSAR(file) ? "true" : "false");

    fclose(file);

    
}


void dumpFile(const char *filename) {
    // Implement the file dump logic
    printf("Dumping file %s...\n", filename);
   
}