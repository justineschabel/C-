//This is a program that takes integers from the command line and converts them to characters
#include <iostream>
#include <stdio.h>
using namespace std;

char Get_Char(unsigned int num){

	char letter = 'a';
	 if((num>>26) & 1) { //if the most significant bit is a 1, it is an upper case	

		for (int i = 0; i < 26; i++){ //for each of the 27 bits, find which bit the 1 is
                    if(num &((1<<i)| (1<<27))){//uppercase 
			letter = i + 'A';
                    }
                }
            }
	    
            else{ //lowercase 
                for (int i = 0; i < 26; i++){
                    if(num &(1<<i)){
			letter = i + 'a'; 
                    }
                }
            }
	return letter;
}

int main(int argc, char *argv[]){

    //initialize variables
    unsigned int num = 0;
    char letter = 'a'; 
    
    cout<<"You entered the word: "; 
 
    for(int i=1; i < argc; i++){ //for each argument (number) given
        sscanf(argv[i], "%u", &num); //scan it in as an unsigned integer
	letter = Get_Char(num);   //get the value/case of each letter and print it
	cout<< letter;         
    }

    cout<<" "; //space between words
    
}
