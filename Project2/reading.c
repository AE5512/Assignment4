// A file consisting of function that will only read fromt he file\
// Alex English

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "seatingGen.h"
#include "reading.h"

#define MAXSEATS 12

SEATASSIGNMENT* readInFile(char* targetFile) {
	SEATASSIGNMENT* seatingPlan = malloc(sizeof(SEATASSIGNMENT) * MAXSEATS);
	FILE* source = fopen(targetFile, "rb");
	if (source == NULL) {
		generateSeatingPlan(targetFile, seatingPlan);
		return seatingPlan;
	}
	for (int i = 0; i < MAXSEATS; ++i) {
		fread(&seatingPlan[i], sizeof(SEATASSIGNMENT), 1, source); // Pulls the information for that seat
	}
	return seatingPlan;
}

// Determines the number of empty seat available
bool emptySeatsTotal(SEATASSIGNMENT* seating) {
	int total = MAXSEATS; // the number of total seats
	for (int i = 0; i < MAXSEATS; ++i) {
		if (seating[i].assigned) {// is the seat assigned
			total = total - 1; //takes a mark off for every seat that it finds assigned
		}
	}
	printf("There are %d empty seats\n\n", total);
	return 1;
}

bool emptySeatsList(SEATASSIGNMENT* seating) {
	printf("The following seat are currently empty:\n");
	for (int i = 0; i < MAXSEATS; ++i) {
		if (seating[i].assigned == 0) {// is the seat assigned
			printf("Seat number %d\n", (i+1)); // Print the number of the empty seat
		}
	}
	printf("\n");
	return 1;
}