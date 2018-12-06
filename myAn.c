//im getting ASCII values instead of characters


//This program takes in two words up to 20 characters and checks if they are anagrams

//libraries
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

//declare functions
int size_string(char orgString[]);
bool compare_function(int sizeOne, int sizeTwo);
void notAnagram(bool check, char orgWord1[], char orgWord2[]);
void lower_string(char orgString[]);
void check_val(int differenceValue, char orgWord1[],char orgWord2[]);
void get_min(char array[20]);
void compare_function2(int difference, char orgWord1Copy[20], char orgWord2Copy[20]);
int exit_function(char array1[20],char array2[20]);


//counts the number of characters before the null character
int size_string(char orgString[]){
    int count = 0;
    while(orgString[count] != '\0'){
        count++;
    }
    return count;
}

//checks to see if the two strings are the same size
bool compare_function(int sizeOne, int sizeTwo){
    if (sizeOne == sizeTwo){
        return true;
    }
    else{
        return false;
    }
    return false;
}

//if the strings arent the same size, this tells the user
void notAnagram(bool check, char orgWord1[], char orgWord2[]){
    if (check == false){
        printf("%s is NOT an anagram of %s", orgWord1, orgWord2);
        exit(0); //exits if they arent anagrams
    }
    return;
}

//if the strings are the same size, this function makes the program case insensitive
void lower_string(char orgString[]){
    int i = 0;
        for (i=0; orgString[i] != '\0'; i++){
            orgString[i] = tolower(orgString[i]);
       
    }
}



void get_min(char array[20]){
    char minimum;
    int i;
    minimum = array[0];
    for (i = 1; i < minimum; i++){
        if (array[i] < minimum){
            minimum = array[i];
            i++;
        }
    }
}


void compare_function2(int difference, char orgWord1Copy[20], char orgWord2Copy[20]){
    if(difference != 0){
        printf("%s is NOT an anagram of %s", orgWord1Copy, orgWord2Copy);
    }
    else if(difference == 0){
        printf("%s is an anagram of %s", orgWord1Copy, orgWord2Copy);
    }
}


int exit_function(char array1[20],char array2[20]){
    int i;
    int difference;
    
    difference = 0;
    for (i=0; array1[i] != '\0' || array2[i]; i++){
        difference += array1[i] - array2[i];
    }
    return difference;
    
}

//main prompts the user and calls the functions
int main(){
//all arrays are set to 20 because the anagrams will be no longer than 20 characters(0-19+\0)
    char orgWord1[20];
    char orgWord2[20];
    char orgWord1Copy[20];
    char orgWord2Copy[20];
    int sizeOne, sizeTwo, difference;
    //int differenceValue, sum1, sum2;
    bool check;
    
    //prompt the user for each word
    printf("Please enter the first word: ");
    scanf(" %s", orgWord1);
    
    printf("Please enter the second word: ");
    scanf(" %s", orgWord2);
    
    strcpy(orgWord1Copy, orgWord1);
    strcpy(orgWord2Copy, orgWord2);
    
    
    //get sizes
    sizeOne = size_string(orgWord1);
    sizeTwo = size_string(orgWord2);
    

    //compare sizes, and get a true or false value
    check = compare_function(sizeOne, sizeTwo);
   
    //add the null character to the end of the size of the array
    orgWord1[sizeOne + 1] = '\0';
    orgWord2[sizeTwo + 1] = '\0';
    
    //if not equal, the program will print that they arent anagrams and exit
    notAnagram(check, orgWord1, orgWord2);
    
    //make the program case insensitive so we can compare ASCII values
    lower_string(orgWord1);
    lower_string(orgWord2);

    get_min(orgWord1);
    get_min(orgWord2);
    
    difference = exit_function(orgWord1, orgWord2);
    
    compare_function2(difference, orgWord1Copy, orgWord2Copy);
    
    return 0;
}



