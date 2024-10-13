#include <iostream>
#include<vector>
using namespace std;

/*
Given two sorted arrays of size n and m respectively, find their union. 
The Union of two arrays can be defined as the common and distinct elements in the two arrays. 
Return the elements in sorted order.
*/

class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //return vector with correct order of elements
        vector<int> union_result;
        int count = 0;
        int i = 0;
        int j = 0;
        
        if(arr1[i]<=arr2[j]){
            union_result.push_back(arr1[i]);
            i++;
            count++;
        }
        else{
            union_result.push_back(arr2[j]);
            j++;
            count++;
        }
        
        // Iterate through both arrays simultaneously.
        while(i<n && j<m){
            if(arr1[i]<=arr2[j]){
                if(arr1[i]!=union_result[count-1]){
                    union_result.push_back(arr1[i]);
                    count++;
                }
                i++;
            }
            else{
                if(arr2[j]!=union_result[count-1]){
                    union_result.push_back(arr2[j]);
                    count++;
                }
                j++;
            }
        }

        // Add remaining elements from arr1.
        while(i<n){
            if(arr1[i]!=union_result[count-1]){
                union_result.push_back(arr1[i]);
                count++;
            }
            i++;
        }

        // Add remaining elements from arr2.
        while(j<m){
            if(arr2[j]!=union_result[count-1]){
                union_result.push_back(arr2[j]);
                count++;
            }
            j++;
        }
        return union_result;
    }
};

int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findUnion(arr1,arr2, N, M);
	    for(int i: ans)cout<<i<<' ';
	    cout << endl;
	    
	}
	
	return 0;
}

