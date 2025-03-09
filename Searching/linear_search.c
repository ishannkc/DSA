#include <stdio.h>

void LinearSearch(int x, int arr[], int size){
    for(int i = 0; i<size; i++){
        if(arr[i] == x ){
            printf("Number found at position: %d \n", i+1);
            return;
        }
    } 
    printf("Element not found!\n");
}

void printArr(int arr[], int size){
    printf("Array: ");
    for(int i = 0; i<size; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main(){

    int arr[] = {1, 45, 23,11,67,88};
    int size = sizeof(arr)/sizeof(arr[0]);

    int n;
    printArr(arr, size);
    printf("Enter the number to be searched from the list: ");
    scanf("%d", &n);

    LinearSearch(n, arr, size);
    
    return 0;
}