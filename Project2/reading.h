#pragma once
#include <stdbool.h>

bool readInFile(TARGETFILE, SEATASSIGNMENT* outList);

bool emptySeatsTotal(char* targetFile); // Total empty seats

bool emptySeatsList(SEATASSIGNMENT* seating); // Each seat that is empty
