#include <bits/stdc++.h> 
using namespace std; 
  
// Vector to store Tree 
vector<vector<int> > graph; 
  
// To check if there 
// is path or not 
int found = 0, n; 
  
// Path and temporary vector 
vector<int> path, temp; 
  
// Count of A and B 
int c_A = 0, c_B = 0; 
  
// Function to find the path connecting 1 to n 
void find(int i, int prev) 
{ 
    // Push the ith node 
    temp.push_back(i); 
  
    // If we reached our destination 
    if (i == n) { 
        path = (temp); 
        return; 
    } 
    for (int j = 0; j < graph[i].size(); j++) 
        if (graph[i][j] != prev) { 
  
            // Dfs for its children 
            find(graph[i][j], i); 
        } 
  
    // Remove the node 
    temp.pop_back(); 
} 
  
// Function to mark all the adjacent 
// unvisited nodes 
void mark(int i, int visited[], int c) 
{ 
    if (!visited[i]) { 
  
        // Increase the count 
        if (c == 1) 
            c_A++; 
        else
            c_B++; 
    } 
  
    visited[i] = c; 
  
    // Increase the count 
    if (c == 1) 
        c_A++; 
    else
        c_B++; 
  
    // Dfs for all its unvisted adjacent nodes 
    for (int j = 0; j < graph[i].size(); j++) 
        if (!visited[graph[i][j]]) 
            mark(graph[i][j], visited, c); 
} 
  
// Function to find the winner among the players 
void findWinner() 
{ 
    // Finds the path 
    find(1, -1); 
  
    int visited[n + 1] = { 0 }; 
  
    for (int i = 0; i < path.size(); i++) { 
  
        // Mark nodes visited by 
        // A as 1 and B as 2 
        if (i < ceil(path.size() / 2.0)) 
            visited[path[i]] = 1, c_A++; 
        else
            visited[path[i]] = 2, c_B++; 
    } 
  
    // Mark all the adjacent unvisted nodes 
    for (int i = 0; i < path.size(); i++) 
        mark(path[i], 
             visited, 
             visited[path[i]]); 
  
    if (c_A > c_B) 
        cout << "A wins"; 
    else if (c_A < c_B) 
        cout << "B wins"; 
    else
        cout << "Draw"; 
} 
  
// Driver code 
int main() 
{ 
    n = 7; 
    graph.clear(); 
    graph.resize(n + 1); 
  
    // Graph 
    graph[6].push_back(4); 
    graph[4].push_back(6); 
    graph[6].push_back(5); 
    graph[5].push_back(6); 
    graph[5].push_back(7); 
    graph[7].push_back(5); 
    graph[5].push_back(2); 
    graph[2].push_back(5); 
    graph[3].push_back(4); 
    graph[4].push_back(3); 
    graph[1].push_back(4); 
    graph[4].push_back(1); 
  
    findWinner(); 
  
    return 0; 
} 