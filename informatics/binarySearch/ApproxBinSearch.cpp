#include <iostream>
using namespace std;

void binarySearch(int *a, int n, int num){
     int l = 0;
     int r = n - 1;
     for(int i = 0; i < 1000; i++){
          int m = (r + l)/2;
          if(a[m] < num){
               l = m + 1;
          }
          else {
               r = m;
          }
     }
         if(a[l] == num){
          cout << num << endl;
         }
         else if(a[l] != num){
         if(num - 1 == a[l]){
                    cout << a[l] << endl;
               }  
               else {
                    cout << num + 1 << endl;
               } 
}
}
     
int main(){
     int k, n;
     cin >> n >> k;
     int a[n];
     int b[k];
     for(int i = 0; i < n; i++){
          cin >> a[i];
     }
     for(int i = 0; i < k; i++){
          cin >> b[i];
     }
     for(int i = 0; i < k; i++){
    binarySearch(a, n, b[i]);
    
     }
     return 0;
}