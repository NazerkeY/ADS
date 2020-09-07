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
     bool ok = true;
     int num = 0;
     cin >> x;
     for(int i = 0; i < n; i++){
     if(a[i] == x){
          ok = true;
          break;
     }
     else{
     ok = false;
     }
     }
     if(ok == true){
          cout << "YES";
     }
     else{
          cout << "NO";
     }
     return 0;
}