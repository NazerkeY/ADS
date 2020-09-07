#include <iostream>
using namespace std;
int main(){
     int x;
     int n;
     cin >> x >> n;
     int a[n];
     for(int i = 0; i < n; i++){
          cin >> a[i];
     }
     for(int i = 0; i < n; i++){
          if(a[i] == x){
               cout << "YES\n";
          }
          else{
               cout << "NO\n";
          }
     }
}