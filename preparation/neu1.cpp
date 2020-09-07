#include <iostream>
using namespace std;
int main()
{
    int n, q;
    cin >> n;
    int h[n];
    for( int i = 0; i < n; i++)
      cin >> h[i];
    cin >> q;
  for( int i = 0; i < q; i++){
    int l, r;
    int res = 0, maxNum = 0;
    cin >> l >> r;
    for( int j = l; j <= r; j++){
      if(maxNum < h[j]){
        maxNum = h[l];
        res++;
      }
    }
    cout << res << endl;
  }
  return 0;
}