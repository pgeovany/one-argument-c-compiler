#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

void outputUnspecified (char *, char *, char **);
void outputSpecified (char *, char *, char*, char **);
void run (char *);
void failure ();
int checkOutput (char *output);

int main(int argc, char **argv){

	char progName[50];
	char command[80];
	char output[80];
	struct stat fileStat;

	if (argv[1] == NULL || argc > 3 || stat(argv[1], &fileStat) < 0) {
		puts("Error: invalid arguments!");
		exit(EXIT_FAILURE);
	}
	else {
		strcpy(progName, argv[1]);
		if(argv[2] == NULL)
			outputUnspecified(progName, command, argv);
		else
			outputSpecified(progName, command, output, argv);

		if(system(NULL))
			run(command);
		else
			failure();
	}
	return 0;
}

void outputUnspecified (char *progName, char *command, char **argv) {
	if (progName[strlen(progName) - 2] != '.' && progName[strlen(progName) - 1] != 'c'){
		puts("Error: The program extension must be '.c'");
		exit(EXIT_FAILURE);
	}
	else {
		progName[strlen(progName) - 2] = '\0';
		sprintf(command, "gcc -o %s %s.c -Wall -lm -ansi -pedantic", progName, progName);
	}
}

void outputSpecified (char *progName, char *command, char *output, char **argv) {
	if (progName[strlen(progName) - 2] != '.' && progName[strlen(progName) - 1] != 'c') {
		puts("Error: You must specify the program extension!");
		exit(EXIT_FAILURE);
	}
	else {
		strcpy(output,argv[2]);
		if (!strcmp(progName, output)){
			puts("Error: The input file cannot be the same as the output file!");
			exit(EXIT_FAILURE);
		}
		else if(checkOutput(output)){
			puts("Error: The extension of the output file must be empty!");
			exit(EXIT_FAILURE);
		}
		else
			sprintf(command, "gcc -o %s %s -Wall -lm -ansi -pedantic", output, progName);
	}
}

int checkOutput (char *output) {
	int i, dot;

	for (i = 1; i < strlen(output); i++) {
		if (output[i] == '.') {
			dot = 1;
			break;
		}
		else
			dot = 0;
	}
	return dot;
}

void run (char *command){
	system(command);
	puts("Done.");
}

void failure() {
	puts("Error: There is not a command processor available.");
	exit(EXIT_FAILURE);
}
