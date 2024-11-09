#pragma once
#include <stdbool.h>

#define NAME_LENGTH 40
typedef struct seatAssignment {
	int num;
	bool assigned;
	char lastName[NAME_LENGTH];
	char firstName[NAME_LENGTH];

} SEATASSIGNMENT;

SEATASSIGNMENT createSeat(int seatNum);

bool generateSeatingPlan(char* seating, SEATASSIGNMENT* seatingPlan);

// A function to print if there is a read/write error. it got annoying to type over and over so it is a function now.
void ioError(char* targetFile);