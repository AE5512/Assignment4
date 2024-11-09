// A file containing all the functions related to writing
// Alex English

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "seatingGen.h"
#include "reading.h"

#define MAXSEATS 12

// Writing the seating plan to a file
bool writeToFile(char* targetFile, SEATASSIGNMENT* seating) {
	FILE* dest = fopen(targetFile, "wb"); // Opens existing file
	if (dest == NULL) {
		generateSeatingPlan(targetFile, seating);
		FILE* source = fopen(targetFile, "rb"); // Opens the newly created file
		return 0;
	}
	for (int i = 0; i < MAXSEATS; ++i) {
		fwrite(&seating[i], sizeof(SEATASSIGNMENT), 1, dest); // Pulls the information for that seat
	}
	free(seating);
	return 1;
}


// a function to assign a seat
bool assignSeat(SEATASSIGNMENT* seating) {
	int seatNum = -1;
	char firstName[40] = { 0 };
	char lastName[40] = { 0 };
	printf("At any prompt type '0' to cancel the command\n");
	printf("Enter the seat number: ");
	scanf_s("%d", &seatNum);
	// Cancel condition
	if (seatNum == 0) {
		printf("Operation canceled\n\n");
		return 0;
	}
	else if (seatNum > MAXSEATS || seatNum < 1) { // Check if the seat num is valid
		fprintf(stderr, "Error, this seat does not exist\n\n");
		return 0;
	}
	// Check if the seat is already taken
	else if (seating[(seatNum - 1)].assigned == 1) {
		fprintf(stderr, "Error, this seat is already assigned\n\n");
		return 0;
	}
	char cancelCon[1] = "0"; // defining a string so i can apply the cancel condition to the string inputs
	// passenger's first name
	printf("Enter customer's first name: ");
	scanf_s("%40s", &firstName, 40);
	// Cancel condition
	if (firstName[0] == cancelCon[0]) {
		printf("Operation canceled\n\n");
		return 0;
	}
	// passenger's last name
	printf("Enter customer's last name: ");
	scanf_s("%40s", &lastName, 40);
	// Cancel condition
	if (lastName[0] == cancelCon[0]) {
		printf("Operation canceled\n\n");
		return 0;
	}
	// writes the new name over the blank space assigned to designated seat
	strncpy_s(seating[(seatNum - 1)].firstName, 20, firstName, 40);
	strncpy_s(seating[(seatNum - 1)].lastName, 20, lastName, 40);
	seating[(seatNum - 1)].assigned = 1; // Sets the seat to assigned
	printf("Seat assigned\n\n");
	return 1;
}

// a function to unassign a seat
bool unassignSeat(SEATASSIGNMENT* seating) {
	int seatNum = -1;
	char firstName[40] = "*Empty";
	char lastName[40] = "*Null";
	printf("Type '0' to cancel the command\n");
	printf("Enter the seat number: ");
	scanf_s("%d", &seatNum);
	// Cancel condition
	if (seatNum == 0) {
		printf("Operation canceled\n\n");
		return 0;
	}
	else if (seatNum > MAXSEATS || seatNum < 1) { // Check if the seat num is valid
		fprintf(stderr, "Error, this seat does not exist\n\n");
		return 0;
	}
	// Check if the seat is already empty
	else if (seating[(seatNum - 1)].assigned == 0) {
		fprintf(stderr, "Error, this seat is already empty\n\n");
		return 0;
	}
	char conditions[2] = { 'y', 'n' }; // a string contain the confermation and cancel condtions: y/n
	char confirmation[5] = { 0 };
	while (1) {
		// Confermation
		printf("Are you sure you would like to unassign seat #%d (y/n): ", seatNum);
		scanf_s("%5s", confirmation, 5);
		// Cancel condition
		if (tolower(confirmation[0]) == conditions[1]) {
			printf("Operation canceled\n\n");
			return 0;
		}
		// confirm condition
		else if (tolower(confirmation[0]) == conditions[0]) {

			// writes the blank names overtop of the already existing ones
			strncpy_s(seating[(seatNum - 1)].firstName, 20, firstName, 40);
			strncpy_s(seating[(seatNum - 1)].lastName, 20, lastName, 40);
			seating[(seatNum - 1)].assigned = 0; // Sets the seat to empty

		}
	}
}