#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>


#define EXIT_FAILURE 1
#define MEMORY_ALLOCATED 1024  // setting a static amount of memory allocated, as for something this small dynamic amounts would be overcomplicated.

bool copyFileLowercase(char* sourceFilename, char* destFilename) {
	FILE* source = fopen(sourceFilename, "r");
	FILE* dest = fopen(destFilename, "w");

	if (source == NULL) {
		fprintf(stderr, "Error, could not access source file for reading: %s", sourceFilename);
	}
	if (dest == NULL) {
		fprintf(stderr, "Error, could not open destination file for writing: %s", destFilename);
	}
	// Now for the hard part!
	char input[MEMORY_ALLOCATED] = { 0 };
	char output[MEMORY_ALLOCATED] = { 0 };
	while (fgets(input, MEMORY_ALLOCATED, source)) {
		 for (int i = 0; input[i]; i++) {
			output[i] = tolower(input[i]);
		  }
		 fprintf(dest, "%s", output);
		 memset(output, 0, MEMORY_ALLOCATED);
	}
	fclose(source);
	fclose(dest);

}

int main(int argc, char** argv) {
    
	
	printf("There are %d arguments. They are:\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("- %s\n", argv[i]);
    }


    if (argc != 3) {
        fprintf(stderr, "usage: give input and output file names as first and second prompt argument\n");
        exit(EXIT_FAILURE);
    }
	copyFileLowercase(argv[1], argv[2]);
}
