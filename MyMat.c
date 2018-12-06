

//This program takes in two matrices and adds them together
//libraries
#include <stdio.h>
#include <string.h>

void add_function(int matrixA[100][100], int matrixB[100][100], int num_rows, int num_cols);

//this function adds the matrices
void add_function(int matrixA[100][100], int matrixB[100][100], int num_rows, int num_cols){
    int i, j;
    int matrixC[100][100];
    printf("A + B =\n");
    for (i = 0; i < num_rows; i++){
        for (j = 0; j < num_cols; j++){
            matrixC[i][j] = matrixA[i][j] + matrixB[i][j];
            printf("%d ", matrixC[i][j]);

        }
        printf("\n");
    }
    
}

//main prompts the user for information
int main(){
    int num_rows, num_cols, i, j, m, k; //initialize variables
    int matrixA[100][100];
    int matrixB[100][100];
    //prompt user for the dimension of the matrix
    printf("Please enter the number of rows: ");
    scanf(" %d", &num_rows);
    
    printf("Please enter the number of columns: ");
    scanf(" %d", &num_cols);
    
    //prompt user for the numbers in the matrix
    printf("Enter Matrix A ");
    //scan_function(num_rows, num_cols);//scan each value
    for (i=0; i < num_rows; i++){
        for(j=0; j < num_cols; j++){
            scanf(" %d", &matrixA[i][j]); //scan for matrix A
            
        }
    }

    printf("Enter Matrix B ");
    //scan_function(num_rows, num_cols);//scan each value
    for (m=0; m < num_rows; m++){
        for(k=0; k < num_cols; k++){
            scanf(" %d", &matrixB[m][k]); //scan for matrix 2
        }
    }

     add_function(matrixA, matrixB, num_rows, num_cols);
    return 0;
}










