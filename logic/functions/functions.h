#ifndef TRIPORGANIZER_FUNCTIONS_H
#define TRIPORGANIZER_FUNCTIONS_H

#include <stdio.h>
#include "../../model/list/list.h"

void showAllDestinations(List *l);
int comparePrices(const void * a, const void * b);
void planTrip(List *l);
void readNewFile(List * l);

void execute(int option, List * l);
void readWholeFile(FILE * f, List * l);

#endif