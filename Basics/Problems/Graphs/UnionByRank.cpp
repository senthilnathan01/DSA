#include<iostream>
#include<vector>

using namespace std;

// With quick union approach
// TC for find() = O(logN)
// TC for union() = O(logN)
// TC for connected() = O(logN)
// TC for unionFind constructor = O(N)

class UnionFind
{
    private:
    vector<int> root;
    vector<int> rank;

    public:
    UnionFind(int size) : root(size), rank(size)
    {
        for(int i = 0; i < size; i++)
        {
            root[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x)
    {
        while( x != root[x]) x = root[x];
        return x;
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
            else if(rank[rootX] < rank[rootY])
            {
                root[rootX] = rootY;
            }
            else 
            {
                root[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

    bool connected(int x, int y)
    {
        return find(x) == find(y);
    }
};

int main()
{
    // for displaying booleans as literal strings, instead of 0 and 1
    cout << boolalpha;

    UnionFind uf(10);
    // 1-2-5-6-7 3-8-9 4
    uf.unionSet(1,2);
    uf.unionSet(2,5);
    uf.unionSet(5,6);
    uf.unionSet(6,7);

    uf.unionSet(3,8);
    uf.unionSet(8,9);

    cout << uf.connected(1, 5) << endl; // true
    cout << uf.connected(5, 7) << endl; // true
    cout << uf.connected(4, 9) << endl; // false

    // 1-2-5-6-7 3-8-9-4
    uf.unionSet(9,4);
    cout << uf.connected(4,9) << endl; // true

    return 0;
}
