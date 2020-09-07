#include <bits/stdc++.h>
using namespace std;

vector<int> prefix(string s){
     int n = s.size();
     vector<int> pref(n);
     pref[0] = 0;
     for(int i = 1; i < n; i++){
          int k = pref[i - 1];
          while(k > 0 && s[i] != s[k]){
               k = pref[k - 1];
          }
          if(s[i] == s[k])
          pref[i] = k + 1;
          else
          pref[i] = 0;
     }
     return pref;
}

int main(){
     string s1, s2;
     cin >> s1 >> s2;
     string s = s1 + s2;
     string t = s2 + s1;
     vector<int> p = prefix(s);
     vector<int> p2 = prefix(t);
     int maxi = max(p[s.size() - 1], p2[t.size() - 1]);
     cout << maxi;
     return 0;
}