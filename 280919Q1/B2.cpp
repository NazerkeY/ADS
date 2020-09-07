#include <iostream>
using namespace std;
int p[100000];

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

     for(int i =2; i<n; i++)
     for(int j =2; j<i; j++){
          if(i+j == n)
     }
}