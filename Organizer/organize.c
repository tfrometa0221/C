#include "dirManagement.h"
#include "strManipulation.h"

/*
(organize) Organize the target directory.
*/
int organize(char* path) {
	DIR* targetDirectory;
	struct dirent* dp;
	char* extension;

	if ((targetDirectory = checkedOpenDirectory(path)) == NULL) {
		return 0;
	}

	if (chdir(path) == -1) {
		perror("ERROR"); fflush(stderr);
		return 0;
	}

	//move all the files to their general folder (music, movies, shows, pictures, documents, or other).
	//create the directory if its not created already.
	while ((dp = readdir(targetDirectory)) != NULL) {
		char* fileName = malloc(FILENAME_SIZE_LIMIT);
		char* newPath = malloc(DIRECTORY_PATH_SIZE_LIMIT);
		strcpy(fileName, dp->d_name);
		if (strncmp(fileName, ".", 1) != 0 && hasExtension(fileName)) {
			extension = getExtension(fileName);
			if (strcmp(extension, ".c") == 0 || strcmp(extension, ".h") == 0 || strcmp(extension, ".o") == 0 || strcmp(extension, ".out") == 0) {
				continue;
			}
			if (strcmp(extension, ".mp3") == 0) {
				moveToDirectory(newPath, "music", fileName);
			}
			else if (strcmp(extension, ".mkv") == 0) {
				if (getNumberOfTokens(fileName) == 2) {
					moveToDirectory(newPath, "movies", fileName);
				}
				if (getNumberOfTokens(fileName) == 4) {
					moveToDirectory(newPath, "shows", fileName);
				}
			}
			else if (strcmp(extension, ".txt") == 0 || strcmp(extension, ".docx") == 0) {
				moveToDirectory(newPath, "documents", fileName);
			}
			else if (strcmp(extension, ".png") == 0 || strcmp(extension, ".jpg") == 0) {
				moveToDirectory(newPath, "pictures", fileName);
			}
			else {
				moveToDirectory(newPath, "other", fileName);
			}
		}
	}

	//organize the music, movies, and shows
	if (organizeDirectory("music") == 0) {
		fprintf(stderr, organizeDirectoryError, "music"); fflush(stderr);
		return 0;
	}
	if (organizeDirectory("movies") == 0) {
		fprintf(stderr, organizeDirectoryError, "movies"); fflush(stderr);
		return 0;
	}
	if (organizeDirectory("shows") == 0) {
		fprintf(stderr, organizeDirectoryError, "shows"); fflush(stderr);
		return 0;
	}

	if (closedir(targetDirectory) == -1) {
		perror("ERROR"); fflush(stderr);
		return 0;
	}

	return 1;
}