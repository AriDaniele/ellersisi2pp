#include "menu.h"
#include "../utils/utils.h"
#include <stdio.h>
#include <stdlib.h>

#define FIRST_OPTION 1
#define LAST_OPTION 4


void printWelcomeLine() {
	printf("\n\t---===  Welcome to TripOrganizer  ===---\n");
}

void printMenu() {
	printf("\n\t1. Show all destinations\n");
	printf("\t2. Plan a trip\n");
	printf("\t3. Load a different DB\n");
	printf("\n\t4. Exit\n\n");
}

void printOptionError() {
	printf("\n\tError: Option out of range\n\n");
}

int askUserForOption() {
	int option;
	printf("\tChoose an option: ");
	scanf("%d", &option);
	while(getchar() !='\n');
	return  option;
}

int isCorrect(int option) {
	return option >= FIRST_OPTION && option <= LAST_OPTION;
}

int isExit(int option) {
	return option == LAST_OPTION;
}

char * readUserString() {
	int i = 0;
	int size = 10;
	char tmp;
	char *ret = (char *) malloc(sizeof(char) * size);

	scanf("%c", &tmp);
	do {
		i++[ret] = tmp;

		if (i >= size) {
			size *= 2;
			resize(&ret, size);
		}
		scanf("%c", &tmp);
	} while (tmp != '\n');
    i++[ret] = '\0';

	resize(&ret, i + 1);

	return ret;
}

char * askUserForPath() {
    printf("\tAvailable databases: ");
    printf("\n\t\tdata/mainDatabase.nymal");
    printf("\n\t\tdata/secondDatabase.nymal");
	printf("\n\n\tEnter the path of the new DB: ");

	return readUserString();
}

void printFileError(char * file) {
	printf("\n\tError: Couldn't load \"%s\"\n", file);
}

void printSortMenu() {
	printf("\n\tHow do you wanted sorted?\n");
	printf("\t\t1. By name\n");
	printf("\t\t2. By average price\n");
	printf("\t\t3. By distance\n");
	printf("\t\t4. By time\n\n");
}

void printDestination(Destination d, int pos, int option) {
	printf("\n\t-------- %d --------\n", pos);
	printf("\tName:\t\t%s\n", d.name);
	printf("\tCountry:\t%s\n", d.country);

	switch (option) {
		case BY_TIME:
			printf("\tTime:\t\t%.2f h\n", getTimeFromBcn(d)/216000);
			break;
		case BY_DISTANCE:
			printf("\tDistance:\t%.2f km\n", (getDistanceFromBcn(d)/1000));
			break;
		case BY_AVG_PRICE:
			printf("\tAvg Price:\t%.2f\n", getAverageHotelPrice(d));
			break;
	}
}

void printPlanMenu() {
	printf("\n\t1. Show best hotels\n");
	printf("\t2. Show best altitude route\n\n");
}

void printAltitudeMap(char ** map, int n) {
	int i, j;

	printf("\n");
	for (i = 0; i < n; i++) {
		printf("\t");
		for (j = 0; j < n; j++) {
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
}

void printDestinationList(List * l) {
	int i = 0;
	printf("\n\tSelect a destination:\n");

	goStart(l, 0);

	while (!isEnd(*l, 0)) {
		printf("\t\t%d. %s\n", ++i, readPoi(*l, 0).name);
		goNext(l, 0);
	}

	printf("\n");

}

void printAverage(double average) {
	printf("\n\t\tAverage: %.2f\n\n", average);
}


void printTop3(double * prices) {
	int i = 0;

	for (i = 0; i < 3; i++) {
		printf("\t\t%d. %.2f\n", i+1, prices[i]);
	}
}