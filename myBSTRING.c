//This program takes a binary string from the command line and changes the xs to 1s and 0s

//libraries
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//declare function
char* bin_str(char* str, char* ans);

//go through the string and change values
char* bin_str(char* str, char* ans){
    //empty string
    if ((*str) == '\0'){
        printf("%s\n", ans);
    }
    //base case
    else  if ((*str) == '1' || (*str) == '0'){
        bin_str(str + 1, ans);
    }
    //recursive case
    else{
        (*str) = '0';
        bin_str(str+1, ans);
        
        (*str) = '1';
        bin_str(str+1, ans);
        (*str) = 'x';}
    return str;
}


int main(int argc, char * argv[]) {
 
    bin_str(argv[1], argv[1]); //go through the string and print possibilities
   
    return 0;
}


