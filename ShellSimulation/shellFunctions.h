/*
This header file has some constants that are used only in shellFunctions.c.
It also has prototypes for the functions in shellFunctions.c.
*/

#include "libraries.h"

#define invalidCommandError "%s is not a valid command.\n"
#define commandFailedError "%s failed to do its job.\n"
#define changeDirectoryError "Failed to change working directory to %s.\n"

void wd();
int chwd(char* pathname);
int quit();