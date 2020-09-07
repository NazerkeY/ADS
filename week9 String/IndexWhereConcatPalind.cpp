// Input: S1 = “abcdf”, S2 = “sfgba”
// Output: 1
// S1[0..1] = “ab”, S2[2..n-1] = “gba”
// S1 + S2 = “abgba” which is a palindrome.
#include <bits/stdc++.h> 
using namespace std; 
bool isPalindrome(string s, int i, int j) 
{ 
    while (i < j) { 
        if (s[i] != s[j]) 
            return false; 
        i++; 
        j--; 
    } 
    return true; 
} 

int getIndex(string s1, string s2, int len) 
{ 
    int i = 0, j = len - 1; 
    while (i < j) { 
        if (s1[i] != s2[j]) { 
            break; 
        } 
  
        i++; 
        j--; 
    } 

    if (i == j) { 
        return i - 1; 
    } 
  
    else if (isPalindrome(s2, i, j)) 
       return i - 1; 
    else if (isPalindrome(s1, i, j)) 
       return j; 
       return -1; 
} 

int main() 
{ 
    string s1, s2;
    cin >> s1 >> s2;

    int len = s1.length(); 
    cout << getIndex(s1, s2, len); 

    return 0; 
}