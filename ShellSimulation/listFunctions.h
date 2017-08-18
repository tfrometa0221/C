/*
This header file has constants that only the list command uses.
It also has prototypes for functions in listFunctions.c.
*/

#include "libraries.h"

#define SIZE 9
#define FILENAME_SIZE_LIMIT 256
#define openDirectoryError "Failed to open directory to %s.\n"
#define statOnFileError "\nCould not get stat on file %s\n"

DIR* checkedOpenDirectory(char* path);
void printInfo(char* dirName, int hidden, int moreInfo);
void printIfHidden(char* fileName);
void printIfNonHidden(char* fileName);
void printFileName(char* fileName);
void printMoreInfo(struct dirent* dp);