//
//  main.c
//  homework 2.2
//
//  Created by Justine on 10/9/16.
//  Copyright © 2016 Justine. All rights reserved.
//
//This is a program that calculates the square root of user prompted numbers a, b and c
#include <stdio.h>
#include <math.h>
void EquationSolver(double a, double b, double c);

void EquationSolver(double a, double b, double c){
    double underRoot;
    double positiveRoot;
    double posCase;
    double negCase;
    /*underRoot is just what is under the square root of the equation. This allows me to check for a negaive number*/
    underRoot = (b*b) - (4*a*c);
    if (underRoot < 0){
        printf("There are no real solutions\n");
        return;
    }
    else {
        positiveRoot = sqrt(underRoot);
    }
    
    //There are two possibilites. = and - in the quadratic equation
    posCase = (-b + positiveRoot)/(2*a);
    negCase = (-b - positiveRoot)/(2*a);
    
    //if the cases are equal, there is only one solution. Otherwise there are two solutions.
    if (posCase == negCase){
        printf("There is one real solution: %.2lf", posCase);
    }
    else{
        printf("There are 2 real solutions\n");
        printf("Solution 1: %.2lf\nSolution 2: %.2lf\n", posCase, negCase);
    }
    return;
}
int main(void) {
    //initialize variables
    double a;
    double b;
    double c;
    //prompt user for a, b and c
    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    printf("Please enter a: ");
    scanf(" %lf", &a);
    printf("Please enter b: ");
    scanf(" %lf", &b);
    printf("Please enter c: ");
    scanf(" %lf", &c);
    EquationSolver(a, b, c);
    
    
    return 0;
}
