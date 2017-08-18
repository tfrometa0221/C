/*
This file has functions used for the create command such as creating a file,
creating a directory, creating a hard link to a file, and creating a soft
link to a file.
*/

#include "createFunctions.h"

/*
(createFile) Creates a file with the give filePath.
*/
int createFile(char* filePath) {
	int file;
	if ((file = open(filePath, O_CREAT, FILE_MODE)) == -1) {
		fprintf(stderr, creatingFileError, filePath); fflush(stderr);
	}
	return 0;
}

/*
(createDirectory) Creates a directory with the give dirPath.
*/
int createDirectory(char* dirPath) {
	if (mkdir(dirPath, DIRECTORY_MODE) == -1) {
		fprintf(stderr, creatingDirectoryError, dirPath); fflush(stderr);
	}
	return 0;
}

/*
(createHandlink) Creates a hard link to oldName named by linkName.
*/
int createHardlink(char* oldName, char* linkName) {
	if (link(oldName, linkName) == -1) {
		fprintf(stderr, creatingLinkError, linkName); fflush(stderr);
	}
	return 0;
}

/*
(createHandlink) Creates a soft link to oldName named by linkName.
*/
int createSoftLink(char* oldName, char* linkName) {
	if (symlink(oldName, linkName) == -1) {
		fprintf(stderr, creatingLinkError, linkName); fflush(stderr);
	}
	return 0;
}