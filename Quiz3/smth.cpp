#include <bits/stdc++.h>

using namespace std;

long long p[10010];
long long pref[10010];

void precalc() {
  p[0]=1;
  for (int i = 1; i < 10001; i++)
    p[i]=p[i-1]*31;
}

long long hashString(string s) {
  long long h = 0;
  for (int i = 0; i < s.size(); i++) {
    h+=((s[i]-'a')*p[i]);
  }
  return h;
}

void hashcalc(string s) {
  for (int i = 0; i < s.size(); i++) {
    pref[i]=((s[i]-'a')*p[i]);
    if (i)
      pref[i]+=pref[i-1];
  }
}

int main() {
  precalc();
  string s;
  string text;
  cin >> text;
  int T;
  cin >> T;
  int n = text.size();
  for (int t = 0; t < T; t++) {
    cin >> s;
    bool issub = false;
    long long hh = hashString(s);
    int cnt = 0;
    int m = s.size();
    for (int i = 0; i < n - m + 1; i++) {
      int j = i+m-1;
      long long hashij = pref[j];
      if (i)
        hashij-=pref[i-1];
      if (hashij == hh*p[i]) {
        issub = true;
        cnt++;
        break;
      }
    }
    cout << cnt << endl;
    cout << pref;
  }
  
}