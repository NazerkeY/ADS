//abbaabaab //aba //
#include <bits/stdc++.h>
 
using namespace std;

vector <int> prefix(string s) {
  int n = s.size();
  vector <int> pref(n);
  pref[0] = 0;
  for (int i = 1; i < n; i++) {
    int k = pref[i-1];
    while(k > 0 && s[i]!=s[k]) {
      k = pref[k-1];
    }
    if (s[i]==s[k])
      pref[i]=k+1;
    else pref[i]=0;
  }
  return pref;
}

int main() {                   
  string text, pat;
  cin >> text >> pat;
  int n = text.size();
  int m = pat.size();
  vector <int> pref = prefix(pat);
  int i = 0;
  int j = 0;
  while(i < n) {
    if (text[i]==pat[j]) {
      i++;
      j++;
    }
    if (j == m) {
      cout << i-j << " ";
      j = pref[j-1];
    }
    else {
      if (i < n && text[i]!=pat[j])
        if (j > 0)
          j = pref[j-1];
        else i++;
    }
  }
  return 0;
}