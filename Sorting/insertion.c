#include <stdio.h>

void insertionSort(int arr[], int n){
    int i,j,temp;
    for( i = 1; i<n; i++){ // initially a[0] is termed sorted array and a[0+i] are unsorted array
         temp = arr[i];
         j = i-1; 
         while(j>=0 && arr[j]>temp){ //j>=0 moves to the sorted array area and arr[j]>temp, checks if the sorted element is greater than the temp element
            arr[j+1] = arr[j]; //shifts a[j] to the sorted area by moving the compared element to the higher index as it is greater
            j--; // moves to the lower index 
        }
        arr[j+1] = temp; //insert the temp value at the correct position 
    }   
}
void print(int arr[], int n){

    for (int i = 0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main(){

    int arr[] = {10, 7, 6, 5, 1};
    int size = sizeof(arr)/ sizeof(arr[0]); //5 elements, so 5 x 4 bytes = 20 and arr[0] = 4 bytes, 20/4 = 5 which is the array size

    printf("Before Sorting: ");
    print( arr,  size);

    insertionSort(arr, size);

    printf("After Sorting: ");
    print(arr, size);

    return 0;


}