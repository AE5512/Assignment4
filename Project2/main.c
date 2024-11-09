// descrption
// Alex English

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "seatingGen.h"
#include "reading.h"
#include "writing.h"
#include "sort.h"

#define MAXSEATS 12
#define TARGETFILE "SeatPlan.bin"

// Function that will print off the interface
void interface() {
	printf("To choose a function, enter its letter label :\n");
	printf("a) Show number of empty seats\n");
	printf("b) Show list of empty seats\n");
	printf("c) Show alphabetical list(by passenger name) of seats\n");
	printf("d) Assign a customer to a seat assignment\n");
	printf("e) Delete a seat assignment\n");
	printf("f) Quit\n\n");
}

// Switch case that will read the input and activate the matching function
bool interfaceInput(char input[1], SEATASSIGNMENT* seatingPlan) {
	char inputValue = *input; // Converts the input into an int so I can use a switch case
	// switch case to select function
	switch (inputValue)
	{
	case 'a': // a) Show number of empty seats
		emptySeatsTotal(seatingPlan);
		return 1;
	case 'b': // b) Show list of empty seats
		emptySeatsList(seatingPlan);
		return 1;
	case 'c': // c) Show alphabetical list(by passenger name) of seats
		sortNames(seatingPlan);
		return 1;
	case 'd': // d) Assign a customer to a seat assignment
		assignSeat(seatingPlan);
		return 1;
	case 'e': // e) Delete a seat assignment
		unassignSeat(seatingPlan);
		return 1;
	case 'f': // f) Quit
		writeToFile(TARGETFILE, seatingPlan);
		exit(0);
	default: // A valid option is not given
		printf("\ninvalid\n");
		return 0;
	}
}



int main(void) {
	SEATASSIGNMENT* seatingPlan = readInFile(TARGETFILE);
	bool accepetedcommand = 1;
	while (1) {
		// Will only print interface after a valid command was given to prevent spamming the interface in console
		if (accepetedcommand) {
			interface();
			accepetedcommand = 0;
		}
		char input[5];
		printf("> ");
		gets_s(input, 5);
		accepetedcommand = interfaceInput(input, seatingPlan);
	}
}
// Function that will print an error if the target file can not be found
void ioError(char* targetFile) {
	fprintf(stderr, "Error, could not access source file for reading/writing: %s\n", targetFile);
}