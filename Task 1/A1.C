#include <stdio.h>
/*
----------------------------------------------------------------
Write a program in C to count a total
number of duplicate elements in an
array
----------------------------------------------------------------
*/
void count_duplicates(){
    int arr[] = {10,20,10,20,30};
    int n = 0;
    int l = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < l; i++){
        int count = 0;
        for (int j = i+1; j<l;j++){
            if(i!=j){
            if (arr[i] == arr[j]) count++;
            }
        }
        if(count==1) n++;
    }
    printf("The total number of duplicated elements = %d elements\n",n);
    
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
    for (int i = 0; i <len; i++){
        int n = 0;
        for(int j = 0; j < len+1; j++){
            if (i!=j){
                if (arr[i] == arr[j]) n++;}
            }
            if (n == 0) printf("%d is unique number\n", arr[i]);
    }
}
/*
Write C code that defines a function
taking array as input argument and
count the freqequency of each element
of an array.
*/
void count_freq() {
    //Initialize array     
    int arr[] = {10,20,10,30,10};     
    int len = sizeof(arr)/sizeof(arr[0]);    
    int freq[len];    
    int added = -1;    
        
    for(int i = 0; i < len; i++){    
        int count = 1;    
        for(int j = i+1; j < len; j++){    
            if(arr[i] == arr[j]){    
                count++;    
                freq[j] = added;    
            }    
        }    
        if(freq[i] != added)    
            freq[i] = count;    
    }    
    printf("---------------------\n");    
    printf(" Element | frequency\n");    
    printf("---------------------\n");    
    for(int i = 0; i < len; i++){    
        if(freq[i] != added){    
            printf("    %d", arr[i]);    
            printf("    |  ");    
            printf("  %d\n", freq[i]);    
        }    
    }    
    printf("---------------------\n");
}

/*Write a program in C to add
numbers using call by reference.
*/
void add_ref(int *x,int *y,int *result){
    *result = *x +*y;
}
int main(){

    count_duplicates();
    unique_element();
    count_freq();

    printf("Enter two numbers to add:\n");
    int num1,num2,sum;
    scanf("%d%d", &num1, &num2);
    add_ref(&num1,&num2,&sum);
    printf("\nThe Sum of %d and %d is %d",num1,num2,sum);
    return 0;
}

