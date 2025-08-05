// Slightly better than mergeSort as it doesn't take up extra space (other recursion stack space)

// TC = O(logn * n)
// SC = O(1)

// MAIN POINTS:
/*
1. Pivot Selection
2. Partitioning
3. Recursive Sorting

- Pivot Selection:
An element from the array is chosen as the "pivot."
The choice of pivot can significantly impact performance, with common strategies including selecting the first element, last element, middle element, or a random element.
  
- Partitioning:
The core of Quick Sort lies in the partitioning step.
Elements in the array are rearranged such that all elements smaller than the pivot are moved to its left, and all elements greater than the pivot are moved to its right.
After partitioning, the pivot element is in its final sorted position.
  
- Recursive Sorting:
Once the array is partitioned, the Quick Sort algorithm is recursively applied to the sub-arrays on both sides of the pivot.
This means the same pivot selection and partitioning steps are performed on the left sub-array (elements smaller than the pivot) and the right sub-array (elements greater than the pivot).

- Base Case:
The recursion continues until a sub-array contains zero or one element, at which point it is considered sorted and the recursion stops for that branch.
*/

// Also, this is a divide and conquer algorithm

class Solution {
  public:
    void quickSort(vector<int>& arr, int low, int high) {
        if(low < high)
        {
            int pIndex = partition(arr, low, high);
            // pIndex is partitioning index, arr[pIndex] is now at the right place
          
            quickSort(arr, low, pIndex -1);
            quickSort(arr, pIndex + 1, high);   
        }
    }

  public:
    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[low], l = low, r = high;
        while(l<r)
        {
            while(arr[l] <= pivot && l <= high - 1) l++;
            
            while(arr[r] > pivot && r >= low + 1) r--;
            
            if(l < r) swap(arr[l], arr[r]);
        }
        
        swap(arr[low], arr[r]);
        return r;
    }
};
