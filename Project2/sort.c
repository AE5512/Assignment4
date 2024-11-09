// a file containing all functions related to sorting
// Alex English

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "seatingGen.h"
#include "sort.h"

#define MAXSEATS 12

// The sorting algorithm for first names 
int compFirst(const void* elem1, const void* elem2)
{
	SEATASSIGNMENT a = *((SEATASSIGNMENT*)elem1);
	SEATASSIGNMENT b = *((SEATASSIGNMENT*)elem2);
	return (strcmp((char*)a.firstName, (char*)b.firstName));
}
// The sorting algorithm for last names 
int compLast(const void* elem1, const void* elem2)
{
	SEATASSIGNMENT a = *((SEATASSIGNMENT*)elem1);
	SEATASSIGNMENT b = *((SEATASSIGNMENT*)elem2);
	return (strcmp((char*)a.lastName, (char*)b.lastName));
}

// will sort the first or last names of the occupants in alphabetical or the reverse of that
bool sortNames(char* targetFile) {
	bool sortByFirstName;
	bool sortByAscending;
	// Pick between sorting by first name or last name
	printf("Sort using :\n");
	printf("a) First name\n");
	printf("b) Last name\n");
	while (1) {
		char input[5];
		printf("> ");
		gets_s(input, 5);
		if (input[0] == 'a') {
			sortByFirstName = true;
			break;
		}
		else if (input[0] == 'b') {
			sortByFirstName = false;
			break;
		}
	}

	// Pick between sorting by ascending or descending order.
	printf("Sort by:\n");
	printf("a) Ascending\n");
	printf("b) Descending\n");
	while (1) {
		char input[5];
		printf("> ");
		gets_s(input, 5);
		if (input[0] == 'a') {
			sortByAscending = true;
			break;
		}
		else if (input[0] == 'b') {
			sortByAscending = false;
			break;
		}
	}
	FILE* source = fopen(targetFile, "rb");
	SEATASSIGNMENT seating[MAXSEATS];
	//should the file not exist

	if (source == NULL) {
		ioError(targetFile);
		return 0;
	}
	for (int i = 0; i < MAXSEATS; ++i) {
		fread(&seating[i], sizeof(SEATASSIGNMENT), 1, source); // Pulls the information for that seat
	}
	SEATASSIGNMENT seatingClone[MAXSEATS];
	memcpy(seatingClone, seating, sizeof(SEATASSIGNMENT) * MAXSEATS);
	if (sortByFirstName) {
		qsort(seatingClone, MAXSEATS, sizeof(SEATASSIGNMENT), compFirst);
	}
	else {
		qsort(seatingClone, MAXSEATS, sizeof(SEATASSIGNMENT), compLast);
	}
	if (sortByAscending) {
		for (int i = 0; i < MAXSEATS; ++i) {
			if (strcmp((char*)seatingClone[i].firstName, (char*)"*Null") != 0) {
				printf("%s, %s\n", seatingClone[i].lastName, seatingClone[i].firstName);
			}
		}
	}
	else {
		for (int i = (MAXSEATS-1); i >= 0; --i) {
			if (strcmp((char*)seatingClone[i].firstName, (char*)"*Null") != 0) {
				printf("%s, %s\n", seatingClone[i].lastName, seatingClone[i].firstName);
			}
		}
	}
	printf("\n");
	return 1;
}