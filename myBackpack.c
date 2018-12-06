//This program calculates the combination of items with the highest value in a store with a weight limit

//libraries
#include <stdio.h>
#include <stdlib.h>

//define struct
typedef struct Items_Struct{
    int value;
    int weight;
} item;

//declare functions
item* all_items(int num_items, item* items);
int heist_plan (item* items, int num_items, int max_weight, int current_value);
int bigger(int a, int b);

//scan and store the value and weight of each item in the store
item* all_items(int num_items, item* items){
    int i, value, weight;
    for(i=0; i< num_items; i++){
        scanf("%d", &value);
        items[i].value = value;
        scanf("%d", &weight);
        items[i].weight = weight;
    }
    return items;
}

int heist_plan (item* items, int num_items, int max_weight, int current_value){
    int best_value  = current_value;
    int i=0;
    for (i = 0; i < num_items; i++){
        if (items[i].weight <= max_weight){
            best_value = bigger(heist_plan(items + i + 1, num_items - i - 1, max_weight - items[i ].weight, current_value + items[i].value), best_value);
        }
    }
    return best_value;
}

//get max value
int bigger(int a, int b){
    if(a >b){
        return a;
    }
    else{
        return b;
    }
}



int main(){
    int max_weight = 0;
    int num_items = 0;
    int highest_value = 0;
    
    printf("Enter the maximum amount of weight that your bag can hold: ");
    scanf("%d", &max_weight);
    printf("Enter the number of items that are in the jewelry store: ");
    scanf("%d", &num_items);
    printf("Enter your items, one per line (value weight): ");
    
    item* items = (item*)malloc(num_items*sizeof(item));
    items = all_items(num_items, items); //list of all items
    
    highest_value = heist_plan(items, num_items, max_weight, 0);
    
    printf("They most profitable heist will net you $%d in total.", highest_value);
    
    return 0;
}

