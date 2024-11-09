#pragma once
#include <stdbool.h>
#include "seatingGen.h"

SEATASSIGNMENT* readInFile(char* targetFile);

bool emptySeatsTotal(SEATASSIGNMENT* seating); // Total empty seats

bool emptySeatsList(SEATASSIGNMENT* seating); // Each seat that is empty
