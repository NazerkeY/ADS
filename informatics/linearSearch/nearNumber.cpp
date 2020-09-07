#include <iostream>
using namespace std;
int main(){
     int n;
     cin >> n;
     int a[n];
     for(int i = 0; i < n; i++){
          cin >> a[i];
     }
     int x;
     cin >> x;

     for(int i = 0; i < n; i++){
          if(a[i] == x){
               cout << x;
               break;
          }
          else if(a[i] == x - 1){
               cout << a[i];
               break;
          }
          else if(a[i] == x + 1){
               cout << a[i];
               break;
          }
     }
     return 0;
}