# include <bits/stdc++.h>
# define sz(x) (int)((x).size())
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;
 
const int N = (int)3e5 + 5;
const int inf = (int)1e9 + 7;
 
int n, q;
int a[N], b[N];
 
int binSearch(int val){
  int lf = 1, rg = n;
  while(rg - lf > 1){
    int mid = (lf + rg) / 2;
    if(a[mid] < val){
      lf = mid;
    } else{
      rg = mid;
    }
  }
  if(a[lf] >= val){
    return a[lf];
  } else{
    return a[rg];
  }
}
 
int main(){
  cin >> n >> q;
  for(int i = 1; i <= n; ++i){
    cin >> a[i];
  }
  sort(a + 1, a + 1 + n);
  for(int i = 1; i <= q; ++i){
    cin >> b[i];
    cout << binSearch(b[i]) << "\n";
  }
  return 0;
}