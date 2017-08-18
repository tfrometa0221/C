/*
This file has functions used for the list command such as opening a directory
and printing informations to stdout.
*/

#include "listFunctions.h"

/*
(checkedOpenDirectory) Opens the specified directory while error checking.
*/
DIR* checkedOpenDirectory(char* path) {
	DIR* dir;
	if ((dir = opendir(path)) == NULL) {
		fprintf(stderr, openDirectoryError, path); fflush(stderr);
		perror("ERROR"); fflush(stderr);
		return NULL;
	}
	return dir;
}

/*
(printInfo) Prints information of the files in the directory specified by dirName.
It prints only information for hidden file if the integer hidden is 1, else it only
prints information on files that are not hidden. It prints additional information
about the files if the integer moreInfo is 1, else it doesn't print anythign else.
*/
void printInfo(char* dirName, int hidden, int moreInfo) {
	char* wd = malloc(256);
	char* originalDirectory = getcwd(wd, 257);
	DIR* directory;
	struct dirent* dp;

	if ((directory = checkedOpenDirectory(dirName)) == NULL) {
		exit(1);
	}
	chdir(dirName);
	while ((dp = readdir(directory)) != NULL) {
		char* fileName = malloc(FILENAME_SIZE_LIMIT);
		strcpy(fileName, dp->d_name);

		if (moreInfo == 1) {
			printFileName(fileName);
			printMoreInfo(dp);
		}
		else {
			if (hidden == 1) {
				printIfHidden(fileName);
			}
			else {
				printIfNonHidden(fileName);
			}
		}
	}
	chdir(originalDirectory);
}

/*
(printIfHidden) Prints file name on a file specified by fileName only if the file
if a hidden file.
*/
void printIfHidden(char* fileName) {
	if (strncmp(fileName, ".", 1) == 0) {
		printFileName(fileName);
		printf("\n"); fflush(stdout);
	}
}

/*
(printIfNonHidden) Prints file name on a file specified by fileName only if the file
if a non-hidden file.
*/
void printIfNonHidden(char* fileName) {
	if (strncmp(fileName, ".", 1) != 0) {
		printFileName(fileName);
		printf("\n"); fflush(stdout);
	}
}

/*
(printIfHidden) Prints file name on a file specified by fileName.
*/
void printFileName(char* fileName) {
	printf("%s", fileName); fflush(stdout);
}

/*
(printMoreInfo) Prints the size, permisions, and inode number of the file specified
by dp.
*/
void printMoreInfo(struct dirent* dp) {
	struct stat statbuffer;
	if (stat(dp->d_name, &statbuffer) == -1) {
		fprintf(stderr, statOnFileError, dp->d_name);
		return;
	}

	printf(" %ld", statbuffer.st_size); fflush(stdout);
	printf(" %o", statbuffer.st_mode); fflush(stdout);
	printf(" %d\n", dp->d_ino); fflush(stdout);
}