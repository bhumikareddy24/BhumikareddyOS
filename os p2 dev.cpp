#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *sourceFile, *destFile;
    char sourceName[100], destName[100];
    char ch;

    printf("Enter source file name: ");
    scanf("%s", sourceName);
    printf("Enter destination file name: ");
    scanf("%s", destName);

    sourceFile = fopen(sourceName, "r");
    if (sourceFile == NULL) {
        printf("Cannot open source file.\n");
        return 1;
    }

    destFile = fopen(destName, "w");
    if (destFile == NULL) {
        printf("Cannot open destination file.\n");
        fclose(sourceFile);
        return 1;
    }

    
    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, destFile);
    }

    printf("File copied successfully.\n");


    fclose(sourceFile);
    fclose(destFile);

    return 0;
}

