/*Suppose you have a matrix of numbers. 
How can you easily compute the sum of any rectangle 
(i.e. a range [row_start, row_end, col_start, col_end]) of those numbers? 
How would you code this?*/

#include <iostream>
using namespace std; 

int getSum(int** mat, int row_start, int row_end, int col_start, int col_end){

	int sum = 0; 

	for(int i = row_start; i < row_end; i++){
		for (int j = col_start; j < col_end; j++){
			mat[i][j] = 1;
			sum += mat[i][j];
		}
	}


	return sum; 

}

int main(){
	
	int rows = 0;
	int cols = 0; 
	int row_start = 0; 
	int row_end = 0;
	int col_start = 0; 
	int col_end = 0; 

	cout << "Please enter the number of rows: ";
	cin >> rows; 
	cout << "Please enter the number of columns: ";
	cin >> cols;

	cout << "Please enter the dimensions of the rectangle in the following way: row_start, row _end, col_start, col_end" << endl;
	cin >> row_start >> row_end >> col_start >> col_end; 

	int** mat = new int*[rows]; 
	for(int i = 0; i < rows; i++)
		mat[i] = new int[cols];

	int sum = getSum(mat, row_start, row_end, col_start, col_end); 

	cout<< sum << endl;
	
}
