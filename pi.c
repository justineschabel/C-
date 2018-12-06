#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
bool is_valid_formatting(double num_args_read, double num_args_needed);
double get_valid_int(char prompt[]);
double get_pos_int(char prompt[]);
double DistanceFunction(double X, double Y);
double RandomNumGenerator(double HI, double LO);

bool is_valid_formatting(double num_args_read, double num_args_needed){
    char new_line = '\n';
    bool is_valid = true; //assume the format is correct
    if(num_args_read != num_args_needed){ //didn't fill in all the format specifiers
        is_valid = false;//format is not correct
    }
    do{
        scanf("%c", &new_line); //read the next character from the standard input
        if(!isspace(new_line)){ //if it isn't white space
            is_valid = false; //extra stuff there so format isn't valid
        }
    }while(new_line != '\n'); //keep reading characters until you reach the new line character
    return is_valid;
}
//makes sure input for numRows and numCol is positive
double get_valid_int(char prompt[]){
    double num_args_read;
    double num;
    
    do{
        printf("%s", prompt);
        num_args_read = scanf("%lf", &num);
    }
    while(!is_valid_formatting(num_args_read, 1.0));
    return num;
}

double get_pos_int(char prompt[]){
    double num_args_read;
    double num;
    do{
        printf("%s", prompt);
        num_args_read = scanf("%lf", &num);
    }
    while( (!is_valid_formatting(num_args_read, 1.0)) || num <= 0);
    return num;
}
double RandomNumGenerator(double HI, double LO){
    double randomNumber;
    randomNumber = LO + ((double)rand()) /(((double)RAND_MAX/(HI-LO)));
    return randomNumber;
}
double DistanceFunction(double X, double Y){
    double dist;
    dist = sqrt((X*X) + (Y*Y)); //distance formula between a point and the origin
    return dist;
}
int main(){
    double randomSeed, numIterations;
    double X, Y, piVal;
    
    randomSeed = get_valid_int("Enter the seed for the random number generator: ");
    srand(randomSeed);
    numIterations = get_pos_int("Enter the number of iterations to run: ");
    
    
    double numInCircle = 0;
    
    for (double i = 1; i <= numIterations; ++i) {
        X = RandomNumGenerator(1, -1);//generate a random x and y
        Y = RandomNumGenerator(1, -1);
        double dist = DistanceFunction(X, Y);
        if (dist <= 1){
            numInCircle += 1;
        }
    }
    
    //printf("%d\n", numInCircle);

    piVal = (double) ((double)numInCircle / (double)numIterations) * 4.0;
    printf("The value of pi is %.5lf.", piVal);    return 0;
}
