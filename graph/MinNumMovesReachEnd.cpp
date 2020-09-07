#include <bits/stdc++.h> 
using namespace std; 
#define N 100005 
  
vector<int> gr[N]; 
  
// Function to add edge 
void add_edge(int u, int v) 
{ 
    gr[u].push_back(v); 
    gr[v].push_back(u); 
} 
  
// Function to return the minimum path 
// from 0th node to the (n - 1)th node 
int dijkstra(int n) 
{ 
    // To check whether an edge is visited or not 
    // and to keep distance of vertex from 0th index 
    int vis[n] = { 0 }, dist[n]; 
  
    for (int i = 0; i < n; i++) 
        dist[i] = INT_MAX; 
  
    // Make 0th index visited and distance is zero 
    vis[0] = 1; 
    dist[0] = 0; 
  
    // Take a queue and push first element 
    queue<int> q; 
    q.push(0); 
  
    // Continue this until all vertices are visited 
    while (!q.empty()) { 
        int x = q.front(); 
  
        // Remove the first element 
        q.pop(); 
  
        for (int i = 0; i < gr[x].size(); i++) { 
  
            // Check if a vertex is already visited or not 
            if (vis[gr[x][i]] == 1) 
                continue; 
  
            // Make vertex visited 
            vis[gr[x][i]] = 1; 
  
            // Store the number of moves to reach element 
            dist[gr[x][i]] = dist[x] + 1; 
  
            // Push the current vertex into the queue 
            q.push(gr[x][i]); 
        } 
    } 
  
    // Return the minimum number of 
    // moves to reach (n - 1)th index 
    return dist[n - 1]; 
} 
  
// Function to return the minimum number of moves 
// required to reach the end of the array 
int Min_Moves(int a[], int n) 
{ 
  
    // To store the positions of each element 
    vector<int> fre[10]; 
    for (int i = 0; i < n; i++) { 
        if (i != n - 1) 
            add_edge(i, i + 1); 
  
        fre[a[i]].push_back(i); 
    } 
  
    // Add edge between same elements 
    for (int i = 0; i < 10; i++) { 
        for (int j = 0; j < fre[i].size(); j++) { 
            for (int k = j + 1; k < fre[i].size(); k++) { 
                if (fre[i][j] + 1 != fre[i][k] 
                    and fre[i][j] - 1 != fre[i][k]) { 
                    add_edge(fre[i][j], fre[i][k]); 
                } 
            } 
        } 
    } 
  
    // Return the required minimum number of moves 
    return dijkstra(n); 
} 
  
// Driver code 
int main() 
{ 
    int a[] = { 1, 2, 3, 4, 1, 5 }; 
    int n = sizeof(a) / sizeof(a[0]); 
  
    cout << Min_Moves(a, n); 
  
    return 0; 
} 