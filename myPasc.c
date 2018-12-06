//loop is incorrect somewhere

//This program prints out the rows of pascals triangle
//libraries needed
#include <stdio.h>
#include <stdlib.h>

//This function prints out the rows of pascals triangle
void fill_function(int num_rows){
    int rowVal[28][28];
    int i, j;
    for (i=0; i<num_rows; i++){
        for(j=0; j<=i; j++){
            if (j==0 ||i==j){
                rowVal[i][j] = 1;
            }
            else if (i != j){
                rowVal[i][j] = rowVal[i-1][j-1] + rowVal[i-1][j];
            }
            printf("%d ", rowVal[i][j]);
        }
        printf("\n");
    }
    
}

//main prompts the user for the size of pascals triangle and calls the function
int main(){
    int num_rows;
 
    
    printf("Please enter how many levels of Pascal's Triangle you would like to see: ");
    scanf("%d", &num_rows);
    
    fill_function(num_rows);
    
    return 0;
}

