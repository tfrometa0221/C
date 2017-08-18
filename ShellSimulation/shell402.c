/*
Tommy Frometa
tfrometa@albany.edu
*/
/*
This file has the main functionalities of the project. It handles many errors,
gets input from the user and process it, and call functions accordinly.
*/

#include "shellFunctions.h"
#include "input.h"

//(main)
int main(int argc, char* argv[]) {
	//Checking for wrong number of arguments
	if (argc > 2 || argc < 1) {
		fprintf(stderr, wrongArgumentNumberError, argv[0]); fflush(stderr);
		exit(1);
	}

	//Open the given file (if any).
	int fd;
	if ((fd = open(argv[1], O_RDONLY)) == NULL) {
		fprintf(stderr, "File %s could not be opened.", argv[1]); fflush(stderr);
		exit(1);
	}
	//Redirect stdin with the file priviously opened.
	if (argc == 2) {
		if (dup2(fd, STDIN_FILENO) == -1) {
			fprintf(stderr, "dup2 failed."); fflush(stderr);
			exit(1);
		}
	}

	//A bunch of self explanaroty variables.
	char* line;

	int forkValue;
	int status;

	char** arguments;
	arguments = malloc(5);
	arguments[4] = NULL;

	char* listPath = malloc(256);
	char* createPath = malloc(256);
	char* cwd = malloc(256);
	getcwd(cwd, 257);

	strcpy(listPath, cwd);
	strcpy(createPath, cwd);
	strcat(listPath, "/list");
	strcat(createPath, "/create");

	//Main finctionalities. Get input and calls other methods accordingly.
	while (1) {
		//Prompt user for imput and process it.
		printf("command? ");
		if((line = getLine(stdin, argc)) == '\0'){
			printf("Tommy\n"); fflush(stdout);
			break;
		}
		if (strcmp(line, "\n") == 0) {
			continue;
		}
		arguments = parseLine(line);
		
		//Call the apporpiate function with the right number of arguments.
		//list
		if (strcmp("list", arguments[0]) == 0) {
			forkValue = fork();

			if (forkValue == 0) {
				execvp(listPath, arguments);
			}
			else {
				wait(&status);
				if (status != 0) {
					fprintf(stderr, commandFailedError, arguments[0]); fflush(stderr);
				}
			}
		}
		//create
		else if (strcmp("create", arguments[0]) == 0) {
			forkValue = fork();

			if (forkValue == 0) {
				execvp(createPath, arguments);
			}
			else {
				wait(&status);
				if (status != 0) {
					fprintf(stderr, commandFailedError, arguments[0]); fflush(stderr);
				}
			}
		}
		//wd
		else if (strcmp("wd", arguments[0]) == 0) {
			wd();
		}
		//chwd
		else if (strcmp("chwd", arguments[0]) == 0) {
			if (arguments[1] == NULL) {
				fprintf(stderr, "No arguments passed to %s.\n", arguments[0]); fflush(stderr);
				continue;
			}
			if (chwd(arguments[1]) != 0) {
				fprintf(stderr, commandFailedError, arguments[0]); fflush(stderr);
			}
		}
		//quit
		else if (strcmp("quit", arguments[0]) == 0) {
			quit();
		}
		//anything else.
		else {
			fprintf(stderr, invalidCommandError, arguments[0]); fflush(stderr);
		}
		printf("\n");
	}
	return 0;
}