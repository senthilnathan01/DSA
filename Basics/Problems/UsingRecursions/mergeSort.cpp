// TC = O(log_2(n)*n)
// SC = O(n)

class Solution {
  public:
    void merge(vector<int> &arr, int low, int mid, int high)
    {
        vector<int> temp;
        int l = low, r = mid + 1;
        while(l <= mid && r <= high)
        {
            if(arr[l]<=arr[r])
            {
                temp.push_back(arr[l]);
                l++;
            }
            else 
            {
                temp.push_back(arr[r]);
                r++;
            }
        }
    
        // Still more left in the first arr
        if(l<=mid)
        {
            temp.insert(temp.end(), arr.begin() + l, arr.begin() + mid + 1);
        }
        
        // Or still more left in the right arr
        if(r <= high)
        {
            temp.insert(temp.end(), arr.begin() + r, arr.begin() + high + 1);
        }
        
        for(int i = low; i <= high; i++)
        {
            arr[i] = temp[i - low];    
        }
    }

    void mergeSort(vector<int>& arr, int l, int r) {
        // Base Case
        int low = l, high = r;
        if(low == high) return;
    
        // Recursive Case
        int mid = (low + high)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
};
