#include <iostream>
using namespace std;
int main(){
     int n;
     int max = -10000000000;
     int index;
     cin >> n;
     int a[n];
     for(int i = 1; i <= n; i++){
          cin >> a[i];
     }

     for(int i = 1; i <= n; i++){
          if(a[i] > max){
               max = a[i];
               index = i;
          }
     }
     cout << max;
}