#include<stdio.h>

void selectionSort(int arr[], int n){
    for(int i = 0; i<n-1; i++){ //running a loop for the pass and pass = n-1
        int min = i; //assume first element to be the smallest value to start with

        for(int j=i+1; j<n; j++){ //running a loop across the unsorted sublist 
            if(arr[j]<arr[min]){
                min = j;    //if value is less, then new min value will be changed
            }
            if(min!=i){
                //swapping smallest element with the comparing element
                int temp = arr [i];
                arr[i] = arr[min];
                arr[min] = temp;
            }
        }
    }
}
void print(int arr[], int n){

    for(int i = 0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){

    int arr[] = {12, 10, 7, 2, 1};
    int size = sizeof(arr)/sizeof(arr[0]);

    printf("Before Sorting: ");
    print(arr, size);

    selectionSort(arr, size);

    printf("After Sorting: ");
    print(arr, size);


    return 0;
}