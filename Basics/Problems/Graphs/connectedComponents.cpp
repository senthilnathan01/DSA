#include<iostream>
#include<vector>
#include<set>
#include<list>

using namespace std;

/*
Given an undirected graph edges, the objective is to return a list of all connected components. 
Each connected component should be represented as a list of its vertices, with all components returned in a collection where each component is listed separately.
*/
class Graph
{
    int V; //No. of vertices

    // Pointer  to an array containing adjacency lists
    list<int>* adj;

    void DFSUtil(int v, bool visited[], vector<int>& connectedComponent);

public:
    Graph(int V); //Constructor
    ~Graph();
    void addEdge(int v, int w);
    vector<vector<int>> connectedComponents();
};

vector<vector<int>> Graph::connectedComponents()
{
    bool *visited = new bool[V];
    for(int v = 0; v<V; v++) visited[v] = false;

    vector<vector<int>> ans;
    for(int v = 0; v<V; v++)
    {
        if(visited[v]==false)
        {
            vector<int> connectedComponent;
            DFSUtil(v, visited, connectedComponent);
            ans.push_back(connectedComponent);
        }
    }
    return ans;
}

void Graph::DFSUtil(int v, bool visited[], vector<int>& connectedComponent)
{
    visited[v]= true;
    connectedComponent.push_back(v);

    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        if(!visited[*i]) DFSUtil(*i, visited, connectedComponent);
    }
}

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

Graph::~Graph()
{
    delete[] adj;
}

// method to add an undirected edge
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

class Solution {
  public:
    vector<vector<int>> connectedcomponents(int v, vector<vector<int>>& edges) {
        Graph g(v);
        vector<vector<int>> ans;

        for(auto vec: edges)
        {
            g.addEdge(vec[0], vec[1]);
        }

        ans = g.connectedComponents();

        return ans;
    }
};

int main()
{
    vector<vector<int>> edges = {{0, 1},{2, 1},{3, 4}};
    Solution obj;
    vector<vector<int>> ans = obj.connectedcomponents(5, edges);
    for(auto vec: ans)
    {
        for(auto num: vec) cout<<num<<" ";
        cout<<endl;
    }
}

// OUTPUT:
// 0 1 2 
// 3 4 
