#include <bits/stdc++.h>
using namespace std;

long long p[10010];
long long pref[10010];

void precalc(){
     p[0] = 1;
     for(int i = 1; i < 10001; i++)
     p[i] = p[i - 1]*31;
}

long long hashString(string s){
     long long h = 0;
     for(int i = 0; i < s.size(); i++){
          h += ((s[i] - 'a')* p[i]);
     }
     return h;
}

void hashCalc(string s){
     for(int i = 0; i < s.size(); i++){
          pref[i] = ((s[i] - 'a')* p[i]);
          if(i)
          pref[i] += pref[i - 1];
     }
}

int main(){
     precalc();
     string text, pat;
     cin >> text;
     hashCalc(text);
     int command;
     cin >> command;
     int n = text.size();
     for(int i = 0; i < command; i++){
          string sub;
          cin >> sub;
          bool isSub = false;
          long long hashSubstr = hashString(sub);
          int cnt = 0; 
          int m = sub.size();
          for(int i = 0; i < n - m + 1; i++){
               int j = i + m - 1;
               long long hashij = pref[j];
               if(i)
               hashij -= pref[i - 1];
               if(hashij == hashSubstr * p[i]){
                    isSub = true;
                    break;
               }
          }
          (isSub == true)?
          cout << "YES\n":
          cout << "NO\n";
     }
     return 0;
}