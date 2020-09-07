//1 3 4 5 
//2 6
#include <bits/stdc++.h> 
using namespace std; 
#define N 100005 
  
// For the graph 
vector<int> gr[N], dis[2]; 
bool vis[N]; 
int colour[N]; 
bool bip; 
  
// Function to add edge 
void Add_edge(int x, int y) 
{ 
    gr[x].push_back(y); 
    gr[y].push_back(x); 
} 
  
// Bipartie function 
void dfs(int x, int col) 
{ 
    vis[x] = true; 
    colour[x] = col; 
  
    // Check for child vertices 
    for (auto i : gr[x]) { 
  
        // If it is not visited 
        if (!vis[i]) 
            dfs(i, col ^ 1); 
  
        // If it is already visited 
        else if (colour[i] == col) 
            bip = false; 
    } 
} 
  
// Function to find two disjoint 
// good sets of vertices in a given graph 
void goodsets(int n) 
{ 
    // Initially assume that graph is bipartie 
    bip = true; 
  
    // For every unvisited vertex call dfs 
    for (int i = 1; i <= n; i++) 
        if (!vis[i]) 
            dfs(i, 0); 
  
    // If graph is not bipartie 
    if (!bip) 
        cout << -1; 
    else { 
  
        // Differentiate two sets 
        for (int i = 1; i <= n; i++) 
            dis[colour[i]].push_back(i); 
  
        // Print vertices belongs to both sets 
  
        for (int i = 0; i < 2; i++) { 
  
            for (int j = 0; j < dis[i].size(); j++) 
                cout << dis[i][j] << " "; 
            cout << endl; 
        } 
    } 
} 
  
// Driver code 
int main() 
{ 
    int n = 6, m = 4; 
  
    // Add edges 
    Add_edge(1, 2); 
    Add_edge(2, 3); 
    Add_edge(2, 4); 
    Add_edge(5, 6); 
  
    // Function call 
    goodsets(n); 
} 