/*
This header file contains all of the libraries that are used thought the whole project.
It also defines some constants that are used in multiple programs of the project.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

#define charSize sizeof(char)
#define intSize sizeof(int)
#define wrongArgumentNumberError "Wrong number of arguments for the %s command.\n"
#define wrongFlagError "Wrong flag for %s command.\n"