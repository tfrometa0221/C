#include <stdio.h>
#include <stdlib.h>
#include "header.h"

/*Takes arguments from command line. The first argument, argc, is the count of arguments passed.
The second argument, argv, is an array of all the arguements. The main function checks for flag
and file errors and call coresponding functions depending on the flag.*/
void main(int argc, char *argv[]){
	
	FILE *in;
	FILE *out;

	if (strcmp("-t", argv[1]) != 0 && strcmp("-b", argv[1]) != 0 && strcmp("-s", argv[1]) != 0) {
		printf("Wrong flag.\n"); fflush(stdout);
		exit(1);
	}
	if (strcmp("-t", argv[1]) == 0) {
		if (argc != 4) {
			printf("Wrong number of arguments for the -t flag.\n"); fflush(stdout);
			exit(1);
		}
		if ((in = fopen(argv[2], "r")) == NULL || (out = fopen(argv[3], "w")) == NULL) {
			fprintf(stderr, "There was a problem opening the files.\n"); fflush(stderr);
			exit(1);
		}
		else {
			textToBinary(in, out);
		}
		
	}
	if (strcmp("-b", argv[1]) == 0) {
		if (argc != 4) {
			printf("Wrong number of arguments for the -b flag.\n"); fflush(stdout);
			exit(1);
		}
		if ((in = fopen(argv[2], "r")) == NULL || (out = fopen(argv[3], "w")) == NULL) {
			fprintf(stderr, "There was a problem opeing the files.\n"); fflush(stderr);
			exit(1);
		}
		else {
			binaryToText(in, out, argv[1]);
		}

	}
	
	if (strcmp("-s", argv[1]) == 0) {
		if (argc != 3) {
			printf("Wrong number of arguments for the -s flag.\n"); fflush(stdout);
			exit(1);
		}
		else {
			if ((in = fopen(argv[2], "r")) == NULL) {
				fprintf(stderr, "There was a problem opeing the file.\n"); fflush(stderr);
				exit(1);
			}
			binaryToText(in, out, argv[1]);
		}
		
	}

	fclose(in);
	fclose(out);
}