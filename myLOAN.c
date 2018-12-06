//
//  1.3.c
//  Homework 1
//
//  Created by Justine on 9/25/16.
//  Copyright © 2016 Justine. All rights reserved.
//
//This program calculates the monthly cost of a loan along with the final, total cost. This calculation assumes the interest will be compounded monthly.
#include <stdio.h>
#include <math.h>

int main(void){
    double moneyBorrowed  = 0;
    double rate = 0 ;
    int numberPayments = 0 ;
    double monthlyPayment = 0;
    double partOfEquation = 0; //for bottom half of equation
    double onePlusInterestRate = 0; // for pow function
    double totalCost = 0;
    double loanCost = 0;
    int negativeNumberPayments = 0;
    
    //prompt the user for basic information
    printf("Please enter the amount of money you borrowed: ");
    scanf(" %lf", &moneyBorrowed);
    printf("$Please enter the annual interest rate: ");
    scanf(" %lf", &rate);
    printf("Please enter the number of payments to be made: ");
    scanf(" %d", &numberPayments);
    
    //split up the problem to assure accuracy
    onePlusInterestRate = 1 + (rate / 12.0);
    negativeNumberPayments = -1 * numberPayments; //-n exponent
    partOfEquation = pow(onePlusInterestRate, negativeNumberPayments);
    monthlyPayment =( (( rate / 12.0) * moneyBorrowed)/ ((1-partOfEquation)));
    
    totalCost = monthlyPayment * numberPayments;
    loanCost = totalCost - moneyBorrowed;
    
    //paragraph explaining information
    printf("A loan of $%.2lf with an annual interest of %.2lf payed off over %d months will have monthly payments of $%.2lf. In total you will pay $%.2lf, making the cost of your loan $%.2lf.\n", moneyBorrowed, rate, numberPayments, monthlyPayment, totalCost, loanCost);
    return 0;
}
