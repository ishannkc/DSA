#include <stdio.h>

void insertionSort(int arr[], int n){
    int i,j,temp;
    for( i = 1; i<n; i++){ 
         temp = arr[i];
         j = i-1; 
         while(j>=0 && arr[j]>temp){ 
            arr[j+1] = arr[j]; 
            j--; 
        }
        arr[j+1] = temp; 
}
}
void print(int arr[], int n){
    printf("List: ");
    for (int i = 0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int BinarySearch(int num, int arr[], int size){
    int left, mid, right;
    left = 0;
    right = size-1;
    while(left<=right){
        mid = (left+right)/2;
        if(arr[mid] == num){
            printf("Element found at position: %d\n", mid+1);
            return mid;
        } else if(arr[mid] < num){
            left = mid +1;
        } else{
            right = mid - 1;
        }
    }
    if(left>right){
         printf("Element not found!\n");
         return -1;
    }   
    
}
int main(){

        int arr[] = {1,45,23,76,8,88,78,4,3,2,11,77,28,17,10, 7, 6};
        int size = sizeof(arr)/ sizeof(arr[0]);

        int num;

        print(arr,size);
        printf("Enter the element to be searched from the array: ");
        scanf("%d", &num);

        printf("\nSorting the array...\n");
        insertionSort(arr,size);
        printf("Sorted array list: ");
        print(arr,size);

        BinarySearch(num, arr, size);

        return 0;
        
}