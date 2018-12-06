#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double make_array(int num_points, FILE* fp);

double make_array(int num_points, FILE* fp){
    int* points_array =(int*)malloc((num_points*2 +1)*sizeof(int)); //an array with then all points
    int i=0;
    double under_root, last_dist = 0;
    double perimeter = 0;
    int num_values = 0;
    num_values = num_points * 2;
    
    fread(points_array +1, sizeof(int), num_values, fp); //copy the points to the array
    
    for(i=1; i <= num_values - 3 ; i+=2){
        under_root = pow(points_array[i]-points_array[i+2], 2) + pow(points_array[i+1] - points_array[i+3],2);
        perimeter += sqrt(under_root); //add to the perimeter
    }
    
    //distance between first and last point
    last_dist = pow(points_array[1] - points_array[num_values - 1], 2) + pow(points_array[2] - points_array[num_values], 2);
    
    free(points_array);//free space
    
    return perimeter + sqrt(last_dist);
    
}
int main(int argc, char** argv){
    FILE* fp = fopen(argv[1], "rb");//open the first character
    int num_points = 0;
    double perimeter = 0;
    
    fseek(fp, 0, SEEK_SET);//go to the beginning of the file
    fread(&num_points, sizeof(int), 1, fp); //read the number of points
    
    perimeter = make_array(num_points,fp);//make an array the size of the number of points and get distance
    
    printf("The perimeter is %.2lf", perimeter);
    
    fclose(fp); // close file
    return 0;
    
}
