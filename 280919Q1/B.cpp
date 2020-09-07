#include <iostream>
using namespace std;
int p[1000000]; 
int x[1000000];
int main(){
     int n;
     int a,b;
     cin>>n;
     for(int i = 2; i * i <= n; i++){
        if (p[i] == 0) {
            int k = i;
            while (k + i < n) {
                k += i;
                p[k] = 1;
            }
        } 
     }

          for(int i=2; i<=n; i++){
           if(p[i]==0){
                x[i] = i;
           }
          }

for(int i=2; i<n; i++){
          if(x[i]!=0){
          for(int j = 2; j<n; j++){
               if(x[i] + x[j] == n ){
                     a = x[i];
                     b = x[j];
                      break; 
               }    
          }  
          }
          } 
         cout<<b<<" "<<a;
     return 0;
}