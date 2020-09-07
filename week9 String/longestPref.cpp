//Input : str = "abcab"
//Output : ab
//Both prefix "a" and "ab" occur two times and the 
//prefix with maximum length is "ab"

#include <bits/stdc++.h> 
using namespace std; 
  
// Function to find Longest prefix string with the  
// highest frequency 
void prefix(string str) 
{ 
    int k = 1, j; 
    int n = str.length(); 
  
    vector<int> g; 
    int flag = 0; 
  
    // storing all indices where first element is found 
    for (int i = 1; i < n; i++) { 
        if (str[i] == str[0]) { 
            g.push_back(i); 
            flag = 1; 
        } 
    } 
  
    // if the first letter in the string does not occur  
    // again  then answer will be the whole string 
    if (flag == 0) { 
        cout << str << endl; 
    } 
    else { 
        int len = g.size(); 
  
        // loop till second appearance of the first element 
        while (k < g[0]) { 
  
            int cnt = 0; 
            for (j = 0; j < len; j++) { 
  
                // check one letter after every stored index 
                if (str[g[j] + k] == str[k]) { 
                    cnt++; 
                } 
            } 
  
            // If there is no mismatch we move forward 
            if (cnt == len) { 
                k++; 
            } 
            // otherwise we stop 
            else { 
                break; 
            } 
        } 
  
        for (int i = 0; i < k; i++) { 
            cout << str[i]; 
        } 
  
        cout << endl; 
    } 
} 
  
// Driver Code 
int main() 
{ 
    string s;
    cin >> s;
    prefix(s); 
  
    return 0; 
} 