/*  Name:    Pi Calculator
    Author:  Adam Douglas
    Purpose: To use different formulae and calculate pi */
    
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

/* These functions calculate pi using different methods */
void lebinizPi();
void bbpPi();
void rsPi();
void glPi();

// Ask the user how many iterations they want
int iterationQuestion(int limit);

// Print the calculated number
void printPi(long double pi);

#define FALSE 0
#define TRUE 1
