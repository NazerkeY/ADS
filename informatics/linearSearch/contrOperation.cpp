#include <iostream>
using namespace std;
int main(){
     int n;
     int max = -10000000;
     int min = 10000000;
     cin >> n;
     int a[n];
     for(int i = 0; i < n; i++){
          cin >> a[i];
     }
     for(int i = 0; i < n; i++){
     if(a[i] > max){
          max = a[i];
     }
     if(a[i] < min){
          min = a[i];
     }
     }

     for(int i = 0; i < n; i++){
          if(a[i] == max){
               a[i] = min;
          }
     }

      for(int i = 0; i < n; i++){
           cout << a[i] << " ";
      }
}