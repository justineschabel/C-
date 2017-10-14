#include <iostream>

using namespace std;

//This program replaces every value of an array with the product of all elements in the array except itself

int main(){
	
	int myAr[5] = {1, 2, 3, 4, 5}; //original array
	int products[5];	       //new array

	for(int i = 0; i < 5; i++){ 		
		products[i] = 1;
		for(int j = 0; j < 5; j++){
			if(myAr[j] != myAr[i])
				products[i] *= myAr[j];
				cout << myAr[j] << endl;
		}
		cout << products[i] << endl;
	}
	
	
}
