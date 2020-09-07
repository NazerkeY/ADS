#include <iostream>
using namespace std;
int main(){
     int n;
     int max1 = -10000000; 
     int max2 = -10000000;
     cin >> n;
     int a[n];

     for(int i = 0; i < n; i++){
          cin >> a[i];
     }
     for(int i = 0; i < n; i++){
          if(a[i] > max1){
               max1 = a[i];
          }
          else if(a[i] > max2 && max2 != max1){
               max2 = a[i];
          }
     }
     cout << max2;
     return 0;
}