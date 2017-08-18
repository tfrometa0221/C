/*
This header file has constants that only the create command uses.
It also has prototypes for functions in createFunctions.c.
*/

#include "libraries.h"

#define FILE_MODE 0640
#define DIRECTORY_MODE 0750
#define failedToCreateError "Failed to create %s %s.\n"
#define noLinkNameError "No link name for flag %s\n"
#define creatingFileError "Could not create file %s\n"
#define creatingDirectoryError "Could not create directory %s\n"
#define creatingLinkError "Could not create link %s\n"

int createFile(char* filePath);
int createDirectory(char* dirPath);
int createHardlink(char* oldName, char* linkName);
int createSoftLink(char* oldName, char* linkName);