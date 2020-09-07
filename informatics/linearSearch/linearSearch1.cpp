#include <iostream>
using namespace std;
int main(){
     int n;
     cin >> n;
     int a[n];
     int x;
     int cnt = 0;

     for(int i = 0; i < n; i++){
          cin >> a[i];
     }

     cin >> x;

     for(int i = 0; i < n; i++){
          if(a[i] == x) cnt++;
     }
     cout << cnt;
}