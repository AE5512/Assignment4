// A file consisting of function that will only read fromt he file\
// Alex English

#include <stdio.h>
#include <stdbool.h>
#include "seatingGen.h"
#include "reading.h"

#define MAXSEATS 12

// Determines the number of empty seat available
bool emptySeatsTotal(char* targetFile) {
	FILE* source = fopen(targetFile, "rb");
	SEATASSIGNMENT seating[MAXSEATS];
	//should the file not exist
	if (source == NULL) {
		ioError(targetFile);
		return 0;
	}
	int total = MAXSEATS; // the number of total seats
	for (int i = 0; i < MAXSEATS; ++i) {
		fread(&seating[i], sizeof(SEATASSIGNMENT), 1, source); // Pulls the information for that seat
		if (seating[i].assigned) {// is the seat assigned
			total = total - 1; //takes a mark off for every seat that it finds assigned
		}
	}
	printf("There are %d empty seats\n\n", total);
	fclose(source);
	return 1;
}

bool emptySeatsList(char* targetFile) {
	FILE* source = fopen(targetFile, "rb");
	SEATASSIGNMENT seating[MAXSEATS];
	//should the file not exist
	if (source == NULL) {
		ioError(targetFile);
		return 0;
	}
	printf("The following seat are currently empty:\n");
	for (int i = 0; i < MAXSEATS; ++i) {
		fread(&seating[i], sizeof(SEATASSIGNMENT), 1, source); // Pulls the information for that seat
		if (seating[i].assigned == 0) {// is the seat assigned
			printf("Seat number %d\n", (i+1)); // Print the number of the empty seat
		}
	}
	printf("\n");
	fclose(source);
	return 1;
}