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
	strncpy_s(newSeat.firstName, NAME_LENGTH, "*null", NAME_LENGTH);

	newSeat.num = seatNum;
	newSeat.assigned = 0;

	return newSeat;
}

bool generateSeatingPlan(char* targetFile) {
	//This y/n prompt was added because i would rather be safe then sorry.
	char conditions[2] = { 'y', 'n' }; // a string contain the confermation and cancel conditions: y/n
	char confirmation[5] = { 0 };
	printf("A new blank seating plan is about to be generated.\n");
	printf("In the event the seating plan got corrupted or does not exist this would fix that.\n");
	printf("If there is already an existing seating plan it will be overwritten\n");
	// If no
	while (1) {
		printf("Create a new blank seating plan (y/n):");
		scanf_s("%5s", confirmation, 5);
		if (tolower(confirmation[0]) == conditions[1]) {
			printf("\n");
			return 0;
		}
		// if yes
		else if (tolower(confirmation[0]) == conditions[1]) {
			//A new seating plan will be generated
			printf("\nGenerating new seating plan\n");
			FILE* dest = fopen(targetFile, "wb");
			SEATASSIGNMENT seating[MAXSEATS];

			for (int i = 0; i < MAXSEATS; ++i) {
				printf("creating new seat num %d\n", i);
				seating[i] = createnewSeat(i);
				fwrite(&seating[i], sizeof(SEATASSIGNMENT), 1, dest);

			}
			printf("\n");
			fclose(dest);
			return 1;
		}
	}
}