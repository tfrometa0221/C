#include "constants.h"

/*Prototypes for dirManagement.c*/

/*
(checkedOpenDirectory) returns a point to a directory after opening it
(moveToDirectory) move a file to a specified directory
(createDirectoryPath) creates a series of directories and subdirectories as needed
(organizeDirectory) organizes a directory
*/
DIR* checkedOpenDirectory(char* path);
void moveToDirectory(char* newPath, char* directory, char* fileName);
char* createDirectoryPath(char** tokenizedFileName, int numberOfTokens);
int organizeDirectory(char* directoryName);