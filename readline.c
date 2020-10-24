#include <stdio.h>
#include <stdlib.h>

#define READLINE_BUFFER 4096

// Function that reads a string input from the user,
//ignoring '/n' and '/r' characters
char *readLine(FILE *stream){
	char *string = NULL;
	int i = 0;

	do{
		if(i%READLINE_BUFFER == 0) {
			string = (char *) realloc(string, (i/READLINE_BUFFER + 1)*READLINE_BUFFER);
		}
		string[i] = fgetc(stream);
		i++;
	}while(string[i-1] != '\n' && string[i-1] != EOF);

	if(i >= 2 && string[i-2] == '\r'){
		string[i-2] = '\0';
		string = (char *) realloc(string, i-1);
	}else{
		string[i-1] = '\0';
		string = (char *) realloc(string, i);
	}

	return string;
}
