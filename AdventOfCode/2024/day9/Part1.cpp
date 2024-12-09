#include<iostream>
#include<vector>
# define ll long long int
using namespace std;

int main()
{
    string input;
    cin>>input;
    // Create the file system
    vector<ll> filesys;
    ll fileID = 0;
    for(int i = 0; i<input.size(); i++)
    {
        if(i%2==0)
        {
            filesys.insert(filesys.end(), int(input[i])-48, fileID);
            fileID++;
        }
        else
        {
            filesys.insert(filesys.end(), int(input[i])-48, -1); //representing '.' by -1
        }
    }
    for(auto num: filesys) cout<<num<<" ";
    cout<<endl;
    // Use two pointers and swap
    int ptr1 = 0;
    int ptr2 = filesys.size()-1;
    while(ptr1<=ptr2)
    {
        while(filesys[ptr1] != -1)
        {
            ptr1++;
        }
        while(filesys[ptr2] == -1)
        {
            ptr2--;
        }
        swap(filesys[ptr1], filesys[ptr2]);
        while(filesys[ptr1] != -1)
        {
            ptr1++;
        }
        while(filesys[ptr2] == -1)
        {
            ptr2--;
        }
    }
    for(auto num: filesys) cout<<num<<" ";
    cout<<endl;
    ll sum = 0;
    for(int i = 0; i<filesys.size(); i++)
    {
        if(filesys[i]== -1) break;
        sum += i*filesys[i];
    }
    cout<<sum;
}