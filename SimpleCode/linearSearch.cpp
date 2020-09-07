#include <iostream>
using namespace std;

int a[10000];
int n, k;
int main(){
     for(int i=0; i<n; i++){
     cin>>a[i];
     }
     for(int i=0; i<n; i++){
          if(a[i]==k){
               cout<<i;
          }
}
     return 0;
}