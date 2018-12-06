//This program takes lists all of the prime numbers between 1 and some i, integer

//libraries
#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

//declare functions
void prime_function(int upperBound);
bool is_valid_formatting(int num_args_read, int num_args_needed);
int get_pos_int(char prompt[]);

bool is_valid_formatting(int num_args_read, int num_args_needed){
    /* check if the format on the entered input is correct
     @num_args_read: the number of format specifiers filled in by scanf
     @num_args_needed: the number of format specifiers you expected to be filled in
     @returns: true if the format is correct and false otherwise
     @side effects: consumes all characters on the standard input
     */
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
int get_valid_int(char prompt[]){
    int num_args_read;
    int num;
    do{
        printf(" %s", prompt);
        num_args_read = scanf("%d", &num);
    }
    while(!(is_valid_formatting(num_args_read, 1))); //if you enter -5 it still works?
    return num;
}

int get_pos_int(char prompt[]){
    int num_args_read;
    int num;
    do{
        printf(" %s", prompt);
        num_args_read = scanf("%d", &num);
    }
    while( !(is_valid_formatting(num_args_read, 1)) || num <= 1 ); //if you enter -5 it still works?
    return num;
}






void prime_function(int upperBound){
    int* initial_prime_number = (int*)malloc(upperBound*sizeof(int));
    int i, j,k, count;
    
    printf("The primes between 2 and %d are:\n", upperBound);
    
    initial_prime_number[0] = 2;
    count=1;
    for (i=3; i <= upperBound; i++){
        for (j=0; j < count; j++){
            if(i % initial_prime_number[j] == 0){
                goto composite;
            }
        }
    count++;
    initial_prime_number = (int*)realloc(initial_prime_number, count*sizeof(int));
    initial_prime_number[count-1] = i;
    composite:
        ;
    }
    for(k=0; k< count; k++){
        printf("%d\n", initial_prime_number[k]);
    }
    

    free(initial_prime_number);
}

//main calls functions and prompts the user for input
int main(){
    int upperBound;
    
    upperBound = get_pos_int("Enter a number greater than 1: ");
    
    
    prime_function(upperBound);
    return 0;
}
