#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.
*/

class UnionFind
{
    private:
    vector<int> root, rank;
    int count;

    public:
    UnionFind(int size) : root(size), rank(size), count(size)
    {
        for(int i = 0; i < size; i++)
        {
            root[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x)
    {
        if(x == root[x]) return x;
        return root[x] = find(root[x]);
    }

    void unionSet(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if(rootX != rootY)
        {
            if(rank[rootX] > rank[rootY])
            {
                root[rootY] = rootX;
            }
            else if(rank[rootY] > rank[rootX])
            {
                root[rootX] = rootY;
            }
            else
            {
                root[rootY] = rootX;
                rank[rootX]++;
            }
            count--;
        }
    }

    int getCount()
    {
        return count;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected)
    {
        if(isConnected.size() == 0) return 0;
        int n = isConnected.size();
        UnionFind uf(n);

        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                if(isConnected[i][j] == 1) uf.unionSet(i, j);
            }
        }
        return uf.getCount();
    }
};

int main()
{
    vector<vector<int>> isConnected =  {{1,1,0}, {1,1,0}, {0,0,1}};
    Solution obj;
    cout<< obj.findCircleNum(isConnected);
    return 0;
}

// OUTPUT:
// 2
