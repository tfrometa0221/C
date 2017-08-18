/*
Tommy Frometa
tfrometa@albany.edu
*/
/*
This file has the main functionalities of the create command. It handles many errors
call funstions to create files.
*/

#include "createFunctions.h"

void main(int argc, char** argv) {
	//Checking for wrong number of arguments
	if (argc > 4 || argc < 3) {
		fprintf(stderr, wrongArgumentNumberError, argv[0]); fflush(stderr);
		exit(1);
	}

	//Creating file or directory.
	if (argc == 3) {
		if (strncmp(argv[1], "-", 1) == 0) {
			//creating file.
			if (strcmp(argv[1], "-f") == 0) {
				if (createFile(argv[2]) != 0) {
					fprintf(stderr, failedToCreateError, "file", argv[2]); fflush(stderr);
					exit(1);
				}
			}
			//creating directory
			if (strcmp(argv[1], "-d") == 0) {
				if (createDirectory(argv[2]) != 0) {
					fprintf(stderr, failedToCreateError, "directory", argv[2]); fflush(stderr);
					exit(1);
				}
			}
		}
		//checking for wrong flag
		else {
			fprintf(stderr, wrongFlagError, argv[0]); fflush(stderr);
			exit(1);
		}
	}
	//creating hard or soft link.
	else {
		if (strncmp(argv[1], "-", 1) == 0) {
			//creating hard link
			if (strcmp(argv[1], "-h") == 0) {
				if (argv[3] == NULL) {
					fprintf(stderr, noLinkNameError, argv[1]); fflush(stderr);
					exit(1);
				}
				if (createHardlink(argv[2], argv[3]) != 0) {
					fprintf(stderr, failedToCreateError, "hard link", argv[3]); fflush(stderr);
					exit(1);
				}
			}
			//creating soft link
			if (strcmp(argv[1], "-s") == 0) {
				if (argv[3] == NULL) {
					fprintf(stderr, noLinkNameError, argv[1]); fflush(stderr);
					exit(1);
				}
				if (createSoftLink(argv[2], argv[3]) != 0) {
					fprintf(stderr, failedToCreateError, "soft link", argv[3]); fflush(stderr);
					exit(1);
				}
			}
		}
		//checking for wrong flag
		else {
			fprintf(stderr, wrongFlagError, argv[0]); fflush(stderr);
			exit(1);
		}
	}
	exit(0);
}