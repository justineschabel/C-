//This program takes in two upper triangular matrices and multiplipies them together
//libraries needed
#include <iostream>
#include <vector>
#include <string>
#include <fstream> 
#include <iterator>
#include <sstream>
#include <stdlib.h> 

//functions
void convert_strs(std::vector<std::string>mat_vals1,std::vector<std::string>mat_vals2, int dimension);
void multiply_mat(std::vector<int>mat1, std::vector<int>mat2, int dimension);
int correct_dim(int row, int col, int dimension);
void print_mat(std::vector<int>mat3); 


//This function puts the values from the files into two matrix vectors
void convert_strs(std::vector<std::string>mat_vals1,std::vector<std::string>mat_vals2, int dimension){
	//declare vectors	
	std::vector<int>mat1;
	std::vector<int>mat2;
	int y = 0;

	//go through the values, convert to ints and put into new vector
	for (std::vector<std::string>::iterator it = mat_vals1.begin()+1 ; it != mat_vals1.end(); ++it){
			std::istringstream convert(*it);
			convert>>y;
			mat1.push_back(y); 
	}
	//do it again for the next vector
	for (std::vector<std::string>::iterator it = mat_vals2.begin()+1 ; it != mat_vals2.end(); ++it){
			std::istringstream convert(*it);
			convert>>y;
			mat2.push_back(y); 
	}
	//now that we have two vectors with the matrix values we can multiply them
	multiply_mat(mat1, mat2, dimension);
}

//this function converts the 2D index to a 1D index
int correct_dim(int row, int col, int dimension){
	int index = 0; 
	int num_0s = row;
	//for each row, add 1 to find the number of 0s you need to skip	
	for (int i = 0; i < row; i++){
		num_0s += i; 
	}
	
	//the index we want is the traditional index minus the 0s that are supposed to be there
	index = (row*dimension + col) - num_0s; 
	return index; 
} 


 //This function multiplies the matrices and calls the print function to print the results 
void multiply_mat(std::vector<int>mat1, std::vector<int>mat2, int dimension)
{	//we need to find the total number of 0s in the matrix 	
	int num_0s = 0;
	for(int i = 0; i < dimension; i++){
		num_0s+= i;
	}
	
	//we need to make a third vector to store the final results
	std::vector<int>mat3; 
	
	int val = 0; 
	int a=0;
	int b =0;
	
	//for each row
	for(int r = 0; r < (dimension*dimension)-num_0s ; r++)
	{	
		//for each column starting at r because we need to skip r 0s
		for(int c = r; c < dimension; c++)
		{
			//reset the value to 0
			val = 0;
			
			//for each element in each row/col until weve reached the last col
			for(int e = r; e <= c ; e++)
			{
				//convert the 2D indices to 1D 
				a = correct_dim(r,e,dimension);
				b = correct_dim(e,c,dimension);
				
				//val will eventually be the sum of all three elements 
				val += (mat1[a] * mat2[b]); 
			}
	
			//finally after going through all of the elements, add it to the final vector
			mat3.push_back(val);
			
			
		}
	
	}
	//print the final vector
	print_mat(mat3);
}	


//This function iterates through the vector and prints the values
void print_mat(std::vector<int>mat3){
	for (std::vector<int>::iterator it = mat3.begin() ; it != mat3.end(); ++it){
		std::cout<<(*it)<<" ";
	}
}


int main(int argc, char* argv[]){

	//declare a vector, get the lines from the file and store them as strings in a vector
	std::vector<std::string>mat_vals1;
	std::string line;
	std::ifstream my_file1;

	my_file1.open(argv[1]);
	while((getline(my_file1, line))){
		mat_vals1.push_back(line);
	}
	my_file1.close();

	//do it again for the second file
	std::vector<std::string>mat_vals2;
	std::ifstream my_file2;
	std::string line2;
	
	my_file2.open(argv[2]);//might need to set this before
	while((getline(my_file2, line2))){
		mat_vals2.push_back(line2);
	}
	my_file2.close();


	//get the first values of the vector (dimension of NXN matrix)
	int N = 0;
	std::string x = "0";

	x = mat_vals1.front();
	std::istringstream convert(mat_vals1.front());
	convert >> N; 
	
	//convert the strings to ints 
	convert_strs(mat_vals1, mat_vals2, N);

	return 0; 
}