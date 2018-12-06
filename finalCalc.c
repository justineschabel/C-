
//  main.c
//  Homework 2.1.c
//
//  Created by Justine on 10/5/16.
//  Copyright © 2016 Justine. All rights reserved.
//
//This is a program to calculate the percent grade needed to get a specific grade in a course

//This program requires three libraries listed below
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
void GradeFunction(char letterGradeWanted);
void FormattingFunction(int num_read, int num_need);

//formatting function from in class
void FormattingFunction(int num_read, int num_need){
    char newLine = '\n';
    if (num_read != num_need){
        printf("Invalid formatting. Ending program.");
        exit(0);
    }
    
    scanf("%c", &newLine);
    if (newLine != '\n'){
        printf("Invalid formatting. Ending program.");
        exit(0);
    }
    
    
}
//calculations 
void GradeFunction(char letterGradeWanted){
    double percentGradeWanted;
    double currentPercentage;
    double percentWeightOfFinal;
    double percentGradeAccumulated;
    double weightOfFinal;
    double percentOnFinal;
    int num_need;
    
//determines the number associated with letterGradeWanted, prompts user for current percentage and accounts for non ABCDF input
    if (toupper(letterGradeWanted) == 'A') {
        percentGradeWanted = 90;
        printf("Enter your current percent in the class: ");
        num_need = scanf(" %lf", &currentPercentage);
        FormattingFunction(num_need, 1);
        
        if (currentPercentage <0){
            printf("The number you last entered should have been positive. Ending program.");
            exit(0);
        }
        
        
    }
    else if (toupper(letterGradeWanted) == 'B') {
        percentGradeWanted = 80;
        printf("Enter your current percent in the class: ");
        num_need = scanf(" %lf", &currentPercentage);
        FormattingFunction(num_need, 1);
        if (currentPercentage <0){
            printf("The number you last entered should have been positive. Ending program.");
            exit(0);
        }
        
    }
    else if (toupper(letterGradeWanted) == 'C') {
        percentGradeWanted = 70;
        printf("Enter your current percent in the class: ");
        num_need = scanf(" %lf", &currentPercentage);
        FormattingFunction(num_need, 1);
        if (currentPercentage <0){
            printf("The number you last entered should have been positive. Ending program.");
            exit(0);
        }
        
    }
    else if (toupper(letterGradeWanted) == 'D') {
        percentGradeWanted = 60;
        printf("Enter your current percent in the class: ");
        num_need = scanf(" %lf", &currentPercentage);
        FormattingFunction(num_need, 1);
        if (currentPercentage <0){
            printf("The number you last entered should have been positive. Ending program.");
            exit(0);
        }
        
    }
    else if (toupper(letterGradeWanted) == 'F') {
        percentGradeWanted = 0;
        printf("Enter your current percent in the class: ");
        num_need = scanf(" %lf", &currentPercentage);
        FormattingFunction(num_need, 1);
        if (currentPercentage <0){
            printf("The number you last entered should have been positive. Ending program.");
            exit(0);
        }
        
        
    }
   else if (letterGradeWanted != 'A' && letterGradeWanted != 'B' && letterGradeWanted != 'C' && letterGradeWanted != 'D' && letterGradeWanted != 'F'){
        printf("Unknown Grade Received: %c. Ending program.\n", letterGradeWanted);
        exit(0);
    }
    else {
        printf("Invalid formatting. Ending program.");
        exit(0);
    }
    
//prompts user for weight of final and accounts for non double or negative input
    
    printf("Enter the weight of the final: ");
    num_need = scanf(" %lf", &percentWeightOfFinal);
    FormattingFunction(num_need, 1);
    
    if (percentWeightOfFinal < 0){
        printf("The number you last entered should have been positive. Ending program.");
        exit(0);
    }
    
    
//determines how much of the current grade is weighted (currentPercentage makes up _% of grade)
    percentGradeAccumulated = 100 - percentWeightOfFinal;
    
//turns weightOfFinal into a decimal for calculation
    weightOfFinal = 0.01 * percentWeightOfFinal;
    
    
//formula to calculate final grade
    percentOnFinal = (percentGradeWanted - ((percentGradeAccumulated *0.01 ) * currentPercentage))/weightOfFinal;
    
//accounts for solution impossible solutions
    if (percentOnFinal > 100){
        printf("You cannot get a %c in the class because you would need to score at least %.2lf%% on the final.", letterGradeWanted, percentOnFinal);
    }
    else if (percentOnFinal >= 0){
        printf("You need a grade of at least %.2lf%% on the final to get a %c in the class.", percentOnFinal, letterGradeWanted);
    }
    else {
        printf("You cannot score low enough on the final to get a %c in the class.", letterGradeWanted);
    }
    return;
}
int main(void) {
//initialization of variables
    char letterGradeWanted;
    int num_need;
    printf("Enter the grade you want in the class: ");
    num_need = scanf(" %c", &letterGradeWanted);
    FormattingFunction(num_need, 1);
    GradeFunction(letterGradeWanted);
    
    
    
    return 0;
}









