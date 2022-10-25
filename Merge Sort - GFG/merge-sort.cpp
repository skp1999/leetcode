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
    int nextGap(int gap)
    {
        if (gap <= 1)
            return 0;
              
        return (int)ceil(gap / 2.0);
    }
    
    public:
    void swap(int nums[], int i, int j)
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    
    public:
    // Space Complexity: O(1)
    void merge(int nums[], int start, int mid, int end)
    {
        int gap = end - start + 1;
          
        for(gap = nextGap(gap); gap > 0; gap = nextGap(gap)) 
        {
            for(int i = start; i + gap <= end; i++) 
            {
                int j = i + gap;
                if (nums[i] > nums[j])
                    swap(nums, i, j);
            }
        }
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        if(l>=r)
            return;
        int m = l + (r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);

    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends