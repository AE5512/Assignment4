#pragma once
#include <stdbool.h>

bool writeToFile(char* targetFile, SEATASSIGNMENT* seating); // write the seating plan to a file 

bool assignSeat(SEATASSIGNMENT* seating);// assignes a seat

bool unassignSeat(SEATASSIGNMENT* seating);// unassignes a seat
