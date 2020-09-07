//Given a graph of N nodes, E edges, a node X and a distance K. 
//The task is to print all the nodes within the distance K from X.
#include <bits/stdc++.h> 
using namespace std; 
  
// Structure of an edge 
struct arr { 
    int from, to; 
}; 
  
// Recursive function to print 
// the neighbor nodes of a node 
// until K distance 
void dfs(int k, int node, 
         int parent, 
         const vector<vector<int> >& tree) 
{ 
  
    // Base condition 
    if (k < 0) 
        return; 
  
    // Print the node 
    cout << node << ' '; 
  
    // Traverse the connected 
    // nodes/adjacency list 
    for (int i : tree[node]) { 
  
        if (i != parent) { 
  
            // node i becomes the parent 
            // of its child node 
            dfs(k - 1, i, node, tree); 
        } 
    } 
} 
  
// Function to print nodes under 
// distance k 
void print_under_dis_K(struct arr graph[], 
                       int node, int k, 
                       int v, int e) 
{ 
  
    // To make graph with 
    // the given edges 
    vector<vector<int> > tree(v + 1, 
                              vector<int>()); 
  
    for (int i = 0; i < e; i++) { 
        int from = graph[i].from; 
        int to = graph[i].to; 
  
        tree[from].push_back(to); 
        tree[to].push_back(from); 
    } 
  
    dfs(k, node, -1, tree); 
} 
  
// Driver Code 
int main() 
{ 
  
    // Number of vertex and edges 
    int v = 7, e = 6; 
  
    // Given edges 
    struct arr graph[v + 1] = { 
        { 2, 1 }, 
        { 2, 5 }, 
        { 5, 4 }, 
        { 5, 7 }, 
        { 4, 3 }, 
        { 7, 6 } 
    }; 
  
    // k is the required distance 
    // upto which are neighbor 
    // nodes should get printed 
    int node = 4, k = 2; 
  
    // function calling 
    print_under_dis_K(graph, node, k, v, e); 
  
    return 0; 
} 