/*  Name:    Pi Calculator
    Author:  Adam Douglas
    Purpose: To use different formulae and calculate pi */
    
#include<iostream>
#include<cmath>
#include<iomanip>

void lebinizPi();
void bbpPi();
void rsPi();
void glPi();
int iterationQuestion(int limit);
int factorial(int a);
void printPi(long double pi);

int main()
{
    bool loop = true;
    std::string tempLoop;
    int menuChoice;
    
    std::cout<<"=========================================="<<std::endl;
    std::cout<<"Welcome To Pi Calculator"<<std::endl;
    std::cout<<"=========================================="<<std::endl;
    std::cout<<std::endl;
    
    do
    {
        std::cout<<"Methods: "<<std::endl;
        std::cout<<std::endl;
        std::cout<<"1 - Lebiniz"<<std::endl;
        std::cout<<"2 - Bailey-Borwein-Plouffle (Faulty)"<<std::endl;
        std::cout<<"3 - Ramanujan-Sato"<<std::endl;
        std::cout<<"4 - Gauss-Legendre Pi"<<std::endl;
        std::cout<<std::endl;
        
        std::cout<<"Which would you like to calculate? "<<std::endl;
        std::cin>>menuChoice;
        while(menuChoice < 1 && menuChoice > 4)
        {
            std::cout<<"Incorrect input. Choose from either 1, 2, 3 or 4."
            <<std::endl;
            std::cout<<"Which would you like to calculate? "<<std::endl;
            std::cin>>menuChoice;
        }       
            
        switch(menuChoice)
        {
            case 1: lebinizPi();
            break;
            case 2: bbpPi();
            break;
            case 3: rsPi();
            break;
            case 4: glPi();
            break;
            default: std::cout<<"An input error occurred. Please try again."
                     <<std::endl;
            break;
        }
        std::cout<<std::endl;
        
        std::cout<<"Would you like to repeat the program? Y/N"<<std::endl;
        std::cin>>tempLoop;
        while(tempLoop != "Y" && tempLoop != "N")
        {
            std::cout<<"Incorrect input. Choose from either Y or N."
            <<std::endl;
            std::cout<<"Would you like to repeat the program? Y/N"<<std::endl;
            std::cin>>tempLoop;
        }
        
        if(tempLoop == "Y")
            loop = true;
        else
            loop = false;
    }
    while(loop == true);   
    
    
    return 0;
}

void lebinizPi()
{
    long double pi = 0;
    int iterations, limit = 999999999;
    
    std::cout<<std::endl;
    std::cout<<"This method requires at least 100000 iterations to be accurate."
    <<std::endl;
    iterations = iterationQuestion(limit);
    
    std::cout<<"Calculating..."<<std::endl;
    
    for(int i = 0; i < iterations; i++)
    {
        pi = pi + pow(-1, i) / (2*i + 1);
    }
    pi = 4*pi;
    
    printPi(pi);
}

void bbpPi()
{
    long double pi = 0, sumAdd = 0;
    int iterations, limit = 256;
    
    std::cout<<std::endl;
    std::cout<<"This method calculates up to 256 digits of pi."<<std::endl;
    iterations = iterationQuestion(limit);
    
    std::cout<<std::fixed;
    std::cout<<std::setprecision(0);
    for(int k = 0; k < iterations; k++)
    {
        pi = (4 / (8*k+1) - 2 / (8*k+4) - 1 / (8*k+5) - 1 / (8*k+6));
        pi = pi * pow(16, -k);
        std::cout<<pi;
    }
}

void rsPi()
{
    long double pi = 0, piMultiply = 2*sqrt(2) / pow(99, 2), sumAdd = 0;
    int iterations, limit = 34;
    
    std::cout<<std::endl;
    std::cout<<"This method requires between 22 and 34 iterations."
    <<std::endl;
    iterations = iterationQuestion(limit);
    
    for(int k = 0; k < iterations; k++)
    {
        sumAdd = factorial(4*k)*(26390*k + 1103);
        sumAdd = sumAdd / ((pow(factorial(k),4)) * pow(396, 4*k));
        pi = pi + sumAdd;
    }
    pi = pow(pi * piMultiply, -1);
    
    printPi(pi);   
}

void glPi()
{
    long double pi = 0, a = 1, b = 1/sqrt(2), t = 0.25, p = 1, tempA;
    int iterations, limit = 999999999;
    
    std::cout<<std::endl;
    std::cout<<"This method doubles in accuracy for each iteration."
    <<std::endl;
    iterations = iterationQuestion(limit);
    
    for(int i = 0; i <= iterations; i++)
    {
        tempA = a;
        a = (tempA + b) / 2;
        b = sqrt(tempA * b);
        t = t - p*pow((tempA - a), 2);
        p = 2 * p;
    }
    pi = (pow((a + b), 2)) / (4 * t);    
    
    printPi(pi);
}

int iterationQuestion(int limit)
{
    int iterations;
    
    std::cout<<std::endl;
    std::cout<<"How many iterations? ";
    std::cin>>iterations;
    
    if(iterations > limit)
        std::cout<<"Too many iterations. Please try again."<<std::endl;
    else if(iterations < 1)
    {
        std::cout<<"Cannot have less than 1 iteration."<<std::endl;
        iterations = 1;
    }
    
    return iterations;
}

int factorial(int a)
{
    int d = 1;
    
    for(int b = 1; b <= a; b++)
    {
        d *= b;
    }
    
    return d;
}    

void printPi(long double pi)
{
    std::cout<<std::fixed;                          
    std::cout<<std::setprecision(43);               
    std::cout<<std::endl;                           
    std::cout<<"The value of pi is "<<pi<<std::endl;
}
