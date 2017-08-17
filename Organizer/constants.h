/*This is a list of constants I find usefull to facilited the writting process
and to amke my code look fancy lol.
*/

#define FILENAME_SIZE_LIMIT 256
#define DIRECTORY_PATH_SIZE_LIMIT 4097
#define DIR_PERMISSIONS 0700
#define wrongArgumentNumber "Wrong number of arguments.\n"
#define organizeSucceed "Target directory has been organized.\n"
#define organizeFailed "Failed to organize target directory.\n"
#define openingDirectoryError "Could not open directory path %s.\n"
#define organizeDirectoryError "Failed to organize directory %s.\n"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>