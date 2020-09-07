# include <bits/stdc++.h>
# define sz(x) (int)((x).size())
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;
 
const int N = (int)3e5 + 5;
const int inf = (int)1e9 + 7;
 
int n;
 
int main(){
  cin >> n;
  int sum = 0;
  for(int i = 2; i * i <= n; ++i){
    while(n % i == 0){
      sum += i;
      n /= i;
    }
  }
  if(n > 1){
    sum += n;
  }
  for(int i = 2; i * i <= sum; ++i){
    while(sum % i == 0){
      sum /= i;
      cout << i << " ";
    }
  }
  if(sum > 1){
    cout << sum;
  }
  return 0;
}