#include "dirManagement.h"
#include "strManipulation.h"

DIR* checkedOpenDirectory(char* path) {
	DIR* dir;
	if ((dir = opendir(path)) == NULL) {
		printf(openingDirectoryError, path); fflush(stdout);
		perror("ERROR"); fflush(stderr);
		return NULL;
	}
	return dir;
}

void moveToDirectory(char* newPath, char* directory, char* fileName) {
	mkdir(directory, DIR_PERMISSIONS);
	strcat(newPath, directory);
	strcat(newPath, "/");
	strcat(newPath, fileName);

	link(fileName, newPath);
	unlink(fileName);
}

char* createDirectoryPath(char** tokenizedFileName, int numberOfTokens) {
	char* dirPath = malloc(256);
	int i;

	strcat(dirPath, tokenizedFileName[0]);
	for (i = 1; i < numberOfTokens; i++) {
		strcat(dirPath, "/");
		strcat(dirPath, tokenizedFileName[i]);
	}

	return dirPath;
}

int organizeDirectory(char* directoryName) {
	DIR* directory;
	struct dirent* dp;
	int flag = 0;

	if ((directory = checkedOpenDirectory(directoryName)) == NULL) {
		return 0;
	}

	if (strcmp(directoryName, "music") == 0) {
		flag = 3;
	}
	else if (strcmp(directoryName, "movies") == 0) {
		flag = 2;
	}
	else if (strcmp(directoryName, "shows") == 0) {
		flag = 4;
	}

	if (chdir(directoryName) == -1) {
		perror("ERROR"); fflush(stderr);
	}

	while ((dp = readdir(directory)) != NULL) {
		char* fileName = malloc(FILENAME_SIZE_LIMIT);
		char** tokenizedFileName;

		strcpy(fileName, dp->d_name);

		if (strncmp(fileName, ".", 1) != 0 && hasExtension(fileName)) {
			tokenizedFileName = getTokenizedFileName(fileName, flag);

			if (flag == 3) {
				mkdir(tokenizedFileName[0], DIR_PERMISSIONS);
				if (chdir(tokenizedFileName[0]) == -1) {
					perror("ERROR"); fflush(stderr);
					return 0;
				}
				mkdir(tokenizedFileName[1], DIR_PERMISSIONS);
				chdir("..");

				rename(fileName, createDirectoryPath(tokenizedFileName, flag));
			}
			else if (flag == 2) {
				mkdir(tokenizedFileName[0], DIR_PERMISSIONS);

				rename(fileName, createDirectoryPath(tokenizedFileName, flag));
			}
			else if (flag == 4) {
				mkdir(tokenizedFileName[0], DIR_PERMISSIONS);
				if (chdir(tokenizedFileName[0]) == -1) {
					perror("ERROR"); fflush(stderr);
					return 0;
				}
				mkdir(tokenizedFileName[1], DIR_PERMISSIONS);
				chdir("..");

				rename(fileName, createDirectoryPath(tokenizedFileName, (flag - 1)));
			}
		}
	}

	chdir("..");
	if(closedir(directory) == -1) {
		perror("ERROR"); fflush(stderr);
		return 0;
	}
	return 1;
}