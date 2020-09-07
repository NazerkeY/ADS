#include <iostream>
using namespace std;
int main(){
     int n;
     cin >> n;
     int a[n];
     for(int i = 1; i <= n; i++){
          cin >> a[i];
     }
     int x;
     cin >> x;
     int index;

     for(int i = 0; i <= n; i++){
          if(a[i] == x){
               index = i;
          }
     }
     cout << index;
     return 0;
}