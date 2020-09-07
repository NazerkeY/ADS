//nput : s = “abcbab”, l = 2
//Output : 4
//All distinct sub-strings of length 2
//will be {“ab”, “bc”, “cb”, “ba”}

#include <bits/stdc++.h> 
#include <set>
#define x 26 
#define mod 3001
using namespace std;

int cntSubstr(string s, int l){
     int hash = 0;
     for(int i = 0; i < l; i++){
          // Finding hash of substring 
    // (0, l-1) using random number x
          hash = hash * x + (s[i] - 97) % mod;
     }
     // Computing x^(l-1) 
     int pow_l = 1;
     for(int i = 0; i < l - 1; i++)
     pow_l = (pow_l * x) % mod;

     set<int> result;
     result.insert(hash);

     for(int i = l; i < s.size(); i++){
          hash = ((hash - pow_l * (s[i - l] - 97) + 2 * mod)
          * x + (s[i] - 97)) % mod;
          result.insert(hash);
     }
     cout << result.size() << endl;   
}
int main(){
     string s;
     cin >> s;
     int l;
     cin >> l;
     cntSubstr(s, l);
     return 0;
}