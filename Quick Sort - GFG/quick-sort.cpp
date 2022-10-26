//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends
class Solution
{
    public:
    void swap(int* a, int* b)
    {
        int t = *a;
        *a = *b;
        *b = t;
    }
      
    /* This function takes last element as pivot, places
    the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
    to left of pivot and all greater elements to right
    of pivot */
    // public:
    // int partition(int arr[], int low, int high)
    // {
    //     int pivot = arr[high]; // pivot
    //     int i = (low - 1); // Index of smaller element and indicates
    //                  // the right position of pivot found so far
      
    //     for (int j = low; j <= high - 1; j++) {
    //         // If current element is smaller than the pivot
    //         if (arr[j] < pivot) {
    //             i++; // increment index of smaller element
    //             swap(&arr[i], &arr[j]);
    //         }
    //     }
    //     swap(&arr[i + 1], &arr[high]);
    //     return (i + 1);
    // }
    
    public:
    int partition (int arr[], int low, int high)
    {
        int pivot = arr[high], pIndex=low-1;
      for(int i=low;i<=high-1;i++) {
          if(arr[i]<pivot) {
              pIndex++;
              swap(&arr[pIndex], &arr[i]);
          }
      }
      swap(&arr[pIndex+1], &arr[high]);
      return pIndex+1; 
    }
    
    
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        if(low>=high)
            return;
        int pIndex = partition(arr, low, high);
        quickSort(arr, low, pIndex-1);
        quickSort(arr, pIndex+1, high);
    }
    
   
};


//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends