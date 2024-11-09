#pragma once
#include <stdbool.h>

#define NAME_LENGTH 40
typedef struct seatAssignment {
	int num;
	bool assigned;
	char lastName[NAME_LENGTH];
	char firstName[NAME_LENGTH];

} SEATASSIGNMENT;

SEATASSIGNMENT creatSeat(int seatNum);

SEATASSIGNMENT assignSeat(int seatNum, bool assigned, char* lastName, char* firstName);

bool importSeating(char* seatingPlan);