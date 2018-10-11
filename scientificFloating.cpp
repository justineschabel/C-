//this program takes in a floating point number and converts it to scientific form
//libraries used 
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
    {
    float my_float = 0;    //initialize variables
    unsigned int exponent =0;
    int index_of_1 = 0;

    cout<<"Please enter a float: "; //get user input
    cin>>my_float;
    cout<<endl;

    unsigned int u_float = *((unsigned int*)&my_float);

    if(((u_float>>23) & 0xFF) == 0){ //0 is a special case 
	cout<<"0E0";
	exit(0);
    }

    exponent = ((u_float >> 23) & 0xFF) -127;//shift to the right 23, & with 8 bits 
    

    cout<<endl;

    if((u_float>>31) & 0x1)  // get the sign bit
    { 
        cout<<"-";
    }

    cout <<"1."; //1. of scientific form
  
   for(int i = 0; i < 23 ; i++){ //find the first one of the mantissa and make a note of the index
	if (u_float & (1<<i)){
		index_of_1 = i; 
		break;
         }
	
    }
    
   
    for(int i = 22; i >= index_of_1 ; i--){//until the last one(LSB) print the value of mantissa
	if( u_float & (1<<i)){ 
		cout<< 1;
	}
	else{
		cout<< 0;	
	}
    }
   
    
    cout<<"E"<<exponent<<endl;
    

}
