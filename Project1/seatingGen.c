// Contain a function that can generate a new blank seating plan

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include "seatingGen.h"


#define NAME_LENGTH 40
SEATASSIGNMENT createnewSeat(int seatNum){
		SEATASSIGNMENT newSeat;

		strncpy_s(newSeat.lastName, NAME_LENGTH, "*Empty", NAME_LENGTH);
		strncpy_s(newSeat.firstName, NAME_LENGTH, "*null", NAME_LENGTH);

		newSeat.num = seatNum;
		newSeat.assigned = 0;

		return newSeat;
}

void generateSeatingPlan(char* targetFile) {
	FILE* dest = fopen(targetFile, "wb");
	SEATASSIGNMENT seating[12];

	for (int i = 0; i < 12; ++i) {
		printf("creating new seat num %d\n", i);
		seating[i] = createnewSeat(i);
		fwrite(&seating[i], sizeof(SEATASSIGNMENT), 1, dest);

	}
	fclose(dest);
}


// a function to assign a seat
bool assignSeat(char* targetFile) {
	FILE* source = fopen(targetFile, "rb");
	SEATASSIGNMENT seating[12];
	for (int i = 0; i < 12; ++i) {
		fread(&seating[i], sizeof(SEATASSIGNMENT), 1, source); // Pulls the information for that seat
	}
	fclose(source);
	int seatnum = -1;
	printf("Enter the seat number: ");
	scanf_s("%d", &seatnum);
	if (seatnum > 12) { // Check if the seat num is valid
		fprintf(stderr, "Error, this seat does not exist\n");
		return 0;
	}
	printf("Enter the seat number: ");
	scanf_s("%d", &seatnum);
	if (sizeof(seatnum) > 40) { // Checks if the first name is to long
		fprintf(stderr, "Error, this name is to long\n");
		return 0;
	}
	printf("Enter the seat number: ");
	scanf_s("%d", &seatnum);
	if (sizeof(seatnum) > 40) { // Checks if the first name is to long
		fprintf(stderr, "Error, this name is to long\n");
		return 0;
	}


	FILE* dest = fopen(targetFile, "wb");
	fclose(dest);
	return 1;
}