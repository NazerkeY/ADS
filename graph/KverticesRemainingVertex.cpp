//2 4
#include <bits/stdc++.h> 
using namespace std; 
#define N 200005 
  
// To store graph 
int n, m, vis[N]; 
vector<int> gr[N]; 
vector<int> v[2]; 
  
// Function to add edge 
void add_edges(int x, int y) 
{ 
    gr[x].push_back(y); 
    gr[y].push_back(x); 
} 
  
// Function to find level of each node 
void dfs(int x, int state) 
{ 
    // Push the vertex in respected level 
    v[state].push_back(x); 
  
    // Make vertex visited 
    vis[x] = 1; 
  
    // Traverse for all it's child nodes 
    for (auto i : gr[x]) 
        if (vis[i] == 0) 
            dfs(i, state ^ 1); 
} 
  
// Function to print vertices 
void Print_vertices() 
{ 
    // If odd level vertices are less 
    if (v[0].size() < v[1].size()) { 
        for (auto i : v[0]) 
            cout << i << " "; 
    } 
    // If even level vertices are less 
    else { 
        for (auto i : v[1]) 
            cout << i << " "; 
    } 
} 
  
// Driver code 
int main() 
{ 
    int n = 4, m = 3; 
  
    // Add edges 
    add_edges(1, 2); 
    add_edges(2, 3); 
    add_edges(3, 4); 
  
    // Function call 
    dfs(1, 0); 
  
    Print_vertices(); 
  
    return 0; 
} 