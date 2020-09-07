#include <bits/stdc++.h>
using namespace std;
int res = 0;
int len;

int main(){
  cin >> len;
  int arr[len];
  for( int i = 0; i < len; i++){
    cin >> arr[i];
  }
  sort(arr, arr + len);
  for( int i = 1; i < len; i++){
    res = res + (arr[i] + arr[0]);
  }
  cout << res;
  return 0;
}