//Im failing the error that passes in a multicharacter response to all three prompts. 
//  main.c
//  official conversions homework
//
//  Created by Justine on 10/10/16.
//  Copyright © 2016 Justine. All rights reserved.
//
//This is a program that takes a temperature or a distance and converts it to another unit, specified by the user
//libraries
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

//functions
bool UnitConversion(char initialSuffix, char convertedSuffix);
void TempOrDist(char tORd);
void FormattingFunction(int num_read, int num_need);

//a function to check for new lines (from lecture)
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

//temperature or distance function and calculation
void TempOrDist(char tORd){
    double temp = 0;
    char initialTSuffix = 'f';
    char convertedTSuffix = 'f';
    double dist = 0;
    char initialDSuffix = 'f';
    char convertedDSuffix = 'f';
    double FtoC = 0;
    double FtoK = 0;
    double CtoF = 0;
    double CtoK = 0;
    double KtoF = 0;
    double KtoC = 0;
    double ItoF = 0;
    double ItoY = 0;
    double ItoM = 0;
    double FtoI = 0;
    double FtoY = 0;
    double FtoM = 0;
    double YtoI = 0;
    double YtoF = 0;
    double YtoM = 0;
    double MtoI = 0;
    double MtoF = 0;
    double MtoY = 0;
    int num_read;
    
//check for Temp or Distance and prompt user for input
    if(strncmp(&tORd, "T",1) == 0) {
        printf("Enter the temperature followed by its suffix (F, C, or K): ");
        num_read = scanf(" %lf %c", &temp, &initialTSuffix);
        FormattingFunction(num_read, 2);
        initialTSuffix = toupper(initialTSuffix);
        if (initialTSuffix != 'F' && initialTSuffix != 'C' && initialTSuffix != 'K'){
            printf("%c is not a valid temperature type. Ending program.", initialTSuffix);
                exit(0);
        }
        printf("Enter the new unit type (F, C, or K): ");
        num_read = scanf(" %c", &convertedTSuffix);
        FormattingFunction(num_read, 1);
        convertedTSuffix = toupper(convertedTSuffix);
        if (convertedTSuffix != 'F' && convertedTSuffix != 'C' && convertedTSuffix != 'K'){
            printf("%c is not a valid temperature type. Ending program.", convertedTSuffix);
            exit(0);
        }
       
        
    }
    else if(strncmp(&tORd, "D", 1) == 0) {
        printf("Enter the distance followed by its suffix (I,F,Y,M): ");
        num_read = scanf(" %lf %c", &dist, &initialDSuffix);
        FormattingFunction(num_read, 2);
        initialDSuffix = toupper(initialDSuffix);
            if (initialDSuffix != 'I' && initialDSuffix != 'F' && initialDSuffix != 'Y' && initialDSuffix != 'M'){
                printf("%c is not a valid distance type. Ending program.\n", initialDSuffix);
                exit(0);
        }
        printf("Enter the new unit type (I,F,Y,M): ");
        num_read = scanf(" %c", &convertedDSuffix);
        FormattingFunction(num_read, 1);
        convertedDSuffix = toupper(convertedDSuffix);
            if (convertedDSuffix != 'I' && convertedDSuffix != 'F' && convertedDSuffix != 'Y' && convertedDSuffix != 'M'){
                printf("%c is not a valid distance type. Ending program.", convertedDSuffix);
                exit(0);
        }
    }
    else{
        printf("Unknown conversion type %c chosen. Ending Program.", tORd);
        exit(0);
    }
    
    
//call unitConversion to see if type is the same
    if(strncmp(&tORd, "T",1) == 0){
        if (UnitConversion(initialTSuffix, convertedTSuffix)){
            printf(" %.2lf", temp);
            printf("%c is ", convertedTSuffix);
            printf("%.2lf", temp);
            printf("%c\n", convertedTSuffix);
        }
        
        
        
//block for Fahrenheit conversion
        if (strncmp(&initialTSuffix, "F", 1) ==0){
            if (strncmp(&convertedTSuffix,"C",1) == 0) {
                FtoC = ((temp - 32.0) * (5.0/9.0));
                printf(" %.2lf", temp);
                printf("F is %.2lf", FtoC);
                printf("C\n");
            }
            else if (strncmp(&convertedTSuffix,"K",1) == 0) {
                FtoK = (temp -32) *(5.0/9.0) + 273.15;
                printf(" %.2lf", temp);
                printf("F is %.2lf", FtoK);
                printf("K\n");
            }
        }
        
//block for celsius conversion
        if (strncmp(&initialTSuffix,"C",1) == 0) {
            if (strncmp(&convertedTSuffix,"F",1) == 0) {
                CtoF = (temp * (9.0/5.0)) + 32;
                printf(" %.2lf", temp);
                printf("C is %.2lf", CtoF);
                printf("F\n");
            }
            else if (strncmp(&convertedTSuffix, "K",1) == 0) {
                CtoK = temp + 273.15;
                printf(" %.2lf", temp);
                printf("C is %.2lf", CtoK);
                printf("K\n");
            }
        }
        
    }
//block for kelvin conversion
    if (strncmp(&initialTSuffix,"K", 1) == 0) {
        
        if (strncmp(&convertedTSuffix,"F", 1) == 0) {
            KtoF = (temp - 273.15)* (9.0/5.0) + 32;
            printf(" %.2lf", temp);
            printf("K is %.2lf", KtoF);
            printf("F\n");
        }
        else if (strncmp(&convertedTSuffix, "C", 1) == 0) {
            KtoC = temp - 273.15;
            printf(" %.2lf", temp);
            printf("K is %.2lf", KtoC);
            printf("C\n");
        }
    }
    
//call unit converson to check if distance type is the same
    if(strncmp(&tORd, "D",1) == 0){
        if (UnitConversion(initialDSuffix, convertedDSuffix)){
            printf(" %.2lf", dist);
            printf("%c is ", convertedDSuffix);
            printf("%.2lf", dist);
            printf("%c\n", convertedDSuffix);
        }
        
//block for inch conversion
        if (strncmp(&initialDSuffix,"I",1) == 0) {
            if (strncmp(&convertedDSuffix,"F",1) == 0) {
                ItoF = dist/12.0;
                printf(" %.2lf", dist);
                printf("I is %.2lf", ItoF);
                printf("F\n");
            }
            else if (strncmp(&convertedDSuffix,"Y",1) == 0) {
                ItoY = dist/36.0;
                printf(" %.2lf", dist);
                printf("I is %.2lf", ItoY);
                printf("Y\n");
            }
            else if (strncmp(&convertedDSuffix,"M",1) == 0) {
                ItoM = dist/63360.0;
                printf(" %.2lf", dist);
                printf("I is %.2lf", ItoM);
                printf("M\n");
            }
        }
//block for foot
        if (strncmp(&initialDSuffix,"F",1) == 0) {
            if (strncmp(&convertedDSuffix,"I",1) == 0) {
                FtoI = dist * 12.0;
                printf(" %.2lf", dist);
                printf("F is %.2lf", FtoI);
                printf("I\n");
            }
            else if (strncmp(&convertedDSuffix,"Y",1) == 0) {
                FtoY = dist/3.0;
                printf(" %.2lf", dist);
                printf("F is %.2lf", FtoY);
                printf("Y\n");
            }
            else if (strncmp(&convertedDSuffix,"M",1) == 0) {
                FtoM = dist/5280.0;
                printf(" %.2lf", dist);
                printf("F is %.2lf", FtoM);
                printf("M\n");
            }
            
        }
    }
//block for yard conversion
    if (strncmp(&initialDSuffix,"Y",1) == 0) {
        if (strncmp(&convertedDSuffix,"F",1) == 0) {
            YtoF = dist * 3.0;
            printf(" %.2lf", dist);
            printf("Y is %.2lf", YtoF);
            printf("F\n");
        }
        else if (strncmp(&convertedDSuffix,"I",1) == 0) {
            YtoI = dist * 36.0;
            printf(" %.2lf", dist);
            printf("Y is %.2lf", YtoI);
            printf("I\n");
        }
        else if (strncmp(&convertedDSuffix,"M",1) == 0) {
            YtoM = dist/1760.0;
            printf(" %.2lf", dist);
            printf("Y is %.2lf", YtoM);
            printf("M\n");
        }
    }
//block for mile conversion
    if (strncmp(&initialDSuffix,"M",1) == 0) {
        if (strncmp(&convertedDSuffix,"I",1) == 0) {
            MtoI = dist * 63360.0;
            printf(" %.2lf", dist);
            printf("M is %.2lf", MtoI);
            printf("I\n");
        }
        else if (strncmp(&convertedDSuffix,"F",1) == 0) {
            MtoF = dist * 5280.0;
            printf(" %.2lf", dist);
            printf("M is %.2lf", MtoF);
            printf("F\n");
        }
        else if (strncmp(&convertedDSuffix,"Y",1) == 0) {
            MtoY = dist * 1760.0;
            printf(" %.2lf", dist);
            printf("M is %.2lf",MtoY);
            printf("Y\n");
        }
    }
    
    
    
    
    
    return;
}

//same unit conversions function
bool UnitConversion(char initialSuffix, char convertedSuffix){
    initialSuffix = toupper(initialSuffix);
    convertedSuffix = toupper(convertedSuffix);
    //printf("R");
    if(strncmp(&initialSuffix, &convertedSuffix, 1) == 0) {
        return true;
    }
    
    return false;
}





//main function
int main(void) {
    char tORd;
    int num_read;
    printf("Pick the type of conversion that you would like to do.\nT or t for temperature\nD or d for distance\nEnter your choice: ");
    num_read = scanf(" %c", &tORd);
    FormattingFunction(num_read, 1);
    TempOrDist(toupper(tORd));
    return 0;
}

