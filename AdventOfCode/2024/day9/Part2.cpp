#include<iostream>
#include<vector>
#include<algorithm>

# define ll long long int

using namespace std;

int main()
{
    string input;
    cin>>input;
    // Create the file system
    vector<vector<ll>> filesys(input.size());
    ll fileID = 0;
    for(int i = 0; i<input.size(); i++)
    {
        if(i%2==0)
        {
            filesys[i].insert(filesys[i].end(), int(input[i])-48, fileID);
            fileID++;
        }
        else
        {
            filesys[i].insert(filesys[i].end(), int(input[i])-48, -1); //representing '.' by -1
        }
    }
    // Remove empty sub-vectors
    filesys.erase(remove_if(filesys.begin(), filesys.end(), [](const vector<ll>& subvec) {
        return subvec.empty();
    }), filesys.end());

    // Approach: 
    // Place a ptr at the right most and it is gonna iterate till it reaches the left most
    // Check for space for the vec from the leftmost till the ptr everytime
    // Insert new remaining -1s as a new vector in the appropriate places
    int ptr2 = filesys.size()-1;
    while(ptr2 >= 0)
    {
        while(filesys[ptr2][0]==-1) ptr2--;
        for(int ptr1 = 0; ptr1 < ptr2; ptr1++)
        {
            while(filesys[ptr1][0]!=-1) ptr1++;
            if(filesys[ptr2].size()<=filesys[ptr1].size() && ptr1<ptr2)
            {
                copy(filesys[ptr2].begin(), filesys[ptr2].begin() + filesys[ptr2].size(), filesys[ptr1].begin());
                // Create a new vector with the remaining -1s and insert next to ptr1
                if(find(filesys[ptr1].begin(),filesys[ptr1].end(), -1) != filesys[ptr1].end())
                {
                    vector<ll> vec(filesys[ptr1].end()-find(filesys[ptr1].begin(),filesys[ptr1].end(), -1));
                    filesys[ptr1].erase(find(filesys[ptr1].begin(),filesys[ptr1].end(), -1), filesys[ptr1].end());
                    fill(vec.begin(), vec.end(), -1);
                    filesys.insert(filesys.begin() + ptr1 + 1, vec);
                    ptr2++; //Place ptr2 in its proper position 
                    fill(filesys[ptr2].begin(), filesys[ptr2].end(), -1);
                }
                else
                {
                    fill(filesys[ptr2].begin(), filesys[ptr2].end(), -1);
                }
                break; 
            }
        }
        ptr2--;
    }
    
    ll sum = 0;
    int index = 0;
    for(int i = 0; i<filesys.size(); i++)
    {
        for(int j = 0; j <filesys[i].size(); j++)
        {
            if(filesys[i][j]!=-1)
            {
                sum += (index)*filesys[i][j];
            }
            index++;
        }
    }
    cout<<sum;
}