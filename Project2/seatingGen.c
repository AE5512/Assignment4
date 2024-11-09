// Contain a function that can generate a new blank seating plan and the definition of the struct
// Alex English

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include "seatingGen.h"

#define MAXSEATS 12
#define NAME_LENGTH 40
SEATASSIGNMENT createnewSeat(int seatNum) {
	SEATASSIGNMENT newSeat;

	strncpy_s(newSeat.lastName, NAME_LENGTH, "*Empty", NAME_LENGTH);
	strncpy_s(newSeat.firstName, NAME_LENGTH, "*Null", NAME_LENGTH);

	newSeat.num = seatNum;
	newSeat.assigned = 0;

	return newSeat;
}

bool generateSeatingPlan(char* targetFile, SEATASSIGNMENT* seating) {
	//A new seating plan will be generated
	printf("\nGenerating new blank seating plan\n");
	for (int i = 0; i < MAXSEATS; ++i) {
		printf("creating new seat num %d\n", i+1);
		seating[i] = createnewSeat(i);
	}
	printf("\n");
	return 1;
}