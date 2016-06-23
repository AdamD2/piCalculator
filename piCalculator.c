/*  Name:    Pi Calculator
    Author:  Adam Douglas
    Purpose: To use different formulae and calculate pi */
    
#include "piCalculator.h"

static int factorial(int a);

int main (int argc, char *argv[]) {
    int loop = TRUE;
    char tempLoop;
    int menuChoice;
    
    printf ("==========================================");
    printf ("Welcome To Pi Calculator");
    printf ("==========================================\n\n");
    
    do {
        // Give choices for Pi methods and get user input
        printf ("Methods: \n\n");
        printf ("1 - Lebiniz\n");
        printf ("2 - Bailey-Borwein-Plouffle (Faulty)\n");
        printf ("3 - Ramanujan-Sato\n");
        printf ("4 - Gauss-Legendre Pi\n\n");
        
        printf ("Which would you like to calculate? ");
        scanf ("%d", &menuChoice);
        // Check that the input is valid
        while (menuChoice < LEIBNIZ && menuChoice > GAUSS) {
            printf ("Incorrect input. Choose from either 1, 2, 3 or 4.");
            printf ("Which would you like to calculate? ");
            scanf ("%d", &menuChoice);
        }       
            
        // Call the relevant functions based on user input
        switch (menuChoice) {
            case LEIBNIZ: lebinizPi ();
            break;
            case BBP: bbpPi ();
            break;
            case RAMANUJAN: rsPi ();
            break;
            case GAUSS: glPi ();
            break;
            default: printf ("An input error occurred. Please try again.");
            break;
        }
        printf ("\n");
        
        // Ask user if they want to repeat the program and check input
        printf ("Would you like to repeat the program? Y/N");
        scanf ("%c", &tempLoop);
        while (tempLoop != 'Y' && tempLoop != 'N') {
            printf ("Incorrect input. Choose from either Y or N.");
            printf ("Would you like to repeat the program? Y/N");
            scanf ("%c", &tempLoop);
        }
        
        // Assign the correct boolean value based on user input
        if (tempLoop == 'Y') {
            loop = TRUE;
        } else {
            loop = FALSE;
        }
    } while (loop == TRUE);   
    
    return EXIT_SUCCESS;
}

void lebinizPi () {
    long double pi = 0;
    int iterations;
    
    printf ("\nThis method requires at least 100000 iterations to be accurate.");
    iterations = iterationQuestion (999999999);
    
    printf ("Calculating...");
    
    // Apply the formula for the number of iterations specified, with 
    // the original formula being 1/4*Pi = 1-1/3+1/5-1/7+1/9 and so on
    for (int i = 0; i < iterations; i++) {
        pi = pi + pow(-1, i) / (2*i + 1);
    }
    // Multiply 4 to get the final result
    pi = 4*pi;
    
    printPi (pi);
}

void bbpPi () {
    long double pi = 0;
    int iterations;
    
    printf ("\nThis method calculates up to 256 digits of pi.");
    iterations = iterationQuestion (256);
    
    // Apply the formula
    for (int k = 0; k < iterations; k++) {
        pi = (4 / (8*k+1) - 2 / (8*k+4) - 1 / (8*k+5) - 1 / (8*k+6));
        pi = pi * pow(16, -k);
        printf ("%Lf", pi);
    }
}

void rsPi () {
    long double pi = 0;
    long double piMultiply = 2*sqrt (2) / pow(99, 2);
    long double sumAdd = 0;
    int iterations;
    
    printf ("\nThis method requires between 22 and 34 iterations.");
    iterations = iterationQuestion (34);
    
    for (int k = 0; k < iterations; k++) {
        sumAdd = factorial(4*k)*(26390*k + 1103);
        sumAdd = sumAdd / ((pow(factorial(k),4)) * pow(396, 4*k));
        pi = pi + sumAdd;
    }
    pi = pow (pi * piMultiply, -1);
    
    printPi (pi);   
}

void glPi () {
    // Declare all of the variables used in the formula
    long double pi = 0, a = 1, b = 1/sqrt(2), t = 0.25, p = 1, tempA;
    int iterations; 
    
    printf("\nThis method doubles in accuracy for each iteration.");
    iterations = iterationQuestion(999999999);
    
    // Assign the variables to each individual part of the formula
    // iteratively
    for(int i = 0; i <= iterations; i++) {
        tempA = a;
        a = (tempA + b) / 2;
        b = sqrt(tempA * b);
        t = t - p*pow((tempA - a), 2);
        p = 2 * p;
    }
    pi = (pow((a + b), 2)) / (4 * t);    
    
    printPi (pi);
}

int iterationQuestion (int limit)
{
    int iterations;
    
    printf ("How many iterations? ");
    scanf ("%d", &iterations);
    
    if (iterations > limit) {
        printf ("Too many iterations. Please try again.");
    } else if (iterations < 1) {
        printf ("Cannot have less than 1 iteration.");
        iterations = 1;
    }
    
    return iterations;
}

int factorial (int a) {
    int d = 1;
    
    // Basic factorial function
    for (int b = 1; b <= a; b++) {
        d *= b;
    }
    
    return d;
}    

void printPi (long double pi) {
    printf("\nThe value of pi is %.60Lf", pi);
}
