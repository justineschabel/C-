//main calls simulations function which calls the moving function
//prompt user again if input is invalid
//print out old and new values for X1 X2 Y1 Y2
//add the total number of rounds throughout all simulations




//libraries needed
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>


//declaration of functions
bool is_valid_formatting(int num_args_read, int num_args_needed);
int get_valid_int(char prompt[]);
bool together(int X1, int Y1, int X2, int Y2);
int move_closer(int start, int end);
int run_meetup(int X1, int Y1, int X2, int Y2, int numSimulations);//fix return statement
double run_meetup_sim(int numRows, int numCol, int numSimulations); //fix
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
    while( !(is_valid_formatting(num_args_read, 1)) || num <= 0 ); //if you enter -5 it still works?
    return num;
}
//checks to see if the points have met up
bool together(int X1, int Y1, int X2, int Y2){
    return X1 == X2 && Y1 == Y2;
}

//moves the pieces closer
int move_closer(int start, int end){
    if (start < end){
        return start + rand() % (end - start + 1);
    }
    else if (start > end){
        return start - rand() % (start - end + 1);
    }
    else {
        return start;
    }
}
int run_meetup(int X1, int Y1, int X2, int Y2, int numSimulations){//might not need numSimulations
    int numRounds = 0;
    int newX1, newY1, newX2, newY2;
    while(!together(X1, Y1, X2, Y2)){
        newX1 = move_closer(X1, X2);
        newY1 = move_closer(Y1, Y2);
        if (numSimulations <= 5){
            printf("First piece moves from %d,%d to %d,%d\n", X1, Y1, newX1 , newY1 );
        }
        newX2 = move_closer(X2, X1);
        newY2 = move_closer(Y2, Y1);
        if (numSimulations <= 5){
            printf("Second piece moves from %d,%d to %d,%d\n", X2, Y2, newX2 , newY2);
        }
        X1 = newX1; Y1 = newY1;
        X2 = newX2; Y2 = newY2;
        
        numRounds++;
    }
    return numRounds;
}

double run_meetup_sim(int numRows, int numCol, int numSimulations){
    int i, X1, Y1, X2, Y2;
    int totalRounds = 0;
    for (i = 0; i < numSimulations; i++ ){
        X1 = rand() % numRows;
        Y1 = rand() % numCol;
        
        X2 = rand() % numRows;
        Y2 = rand() % numCol;
        
        if (numSimulations <= 5){ //only print the moves for simulations < 5?
            printf("Simulation %d\n", i);
            printf("Piece one starts at: %d, %d\n" , X1, Y1);
            printf("Piece two starts at: %d, %d\n" , X2, Y2);
        }
        
        totalRounds += run_meetup(X1, Y1, X2, Y2, numSimulations);//might not need numSimulations
    }
    return (double) totalRounds / (double) numSimulations;
}

//main function that promptst the user and calls function
int main(){
    int seed, numRows, numCol, numSimulations;
    double avgRounds;
    
    seed = get_valid_int("Enter the seed for the random number generator: ");
    
    
    numRows = get_pos_int("Enter the number of rows on the board: ");
    
    
    numCol = get_pos_int("Enter the number of columns on the board: ");
    
    numSimulations = get_pos_int("Enter the number of simulations to run: ");
    
    srand(seed);
    
    avgRounds = run_meetup_sim(numRows, numCol, numSimulations);
    printf("On average it takes %.2lf rounds on a board %d X %d for the pieces to meet.", avgRounds, numRows, numCol); //Final statement
    
    
    return 0;
}
















