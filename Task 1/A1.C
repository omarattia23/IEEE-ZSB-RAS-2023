#include <stdio.h>
/*
----------------------------------------------------------------
Write a program in C to count a total
number of duplicate elements in an
array
----------------------------------------------------------------
*/
void count_duplicates(){
    int arr[] = {1,2,3,4,5,6,7,1,4,6,7};
    int count = 0;
    int l = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < l-1; i++){
        for (int j = i+1; j<l;j++){
            if (arr[i] == arr[j]){
                count++;
                break;
            }
        }
    }
    printf("The total number of duplicated elements = %d elements",count);
    
}
/*
----------------------------------------------------------------
Write a program in C to print all
unique elements in an array.
----------------------------------------------------------------
*/
void unique_element(){
    int arr[] = {1,2,3,1,2,3,4,5};
    int len = sizeof(arr)/sizeof(arr[0]);
    int count = 0;
    for (int i = 0; i <len-1; i++){
        int n = 0;
        for(int j = i+1; j < len; j++){
            if (arr[i] == arr[j]){
                n++;
                break;
            }
        }
        if (n == 0){
            count++;
        }
    }
    printf("\nThe number of unique elements = %d elements", count);
}

int main(){

    count_duplicates();
    unique_element();

    return 0;
}

