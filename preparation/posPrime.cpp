#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
int prime(int n){
    int c = 0;
    for(int i = 2; i * i < n; i++){
        if(n % i == 0){
            return c;
            }
            }
    return n;
}
int main(){
   int n = 100000, i, b;
   vector<int> vec;
   cin >> b;
   for(i = 2; i <= n; i++){
       if(prime(i)!= 0){
           vec.push_back(prime(i));
       }
   }
   cout<<vec[b - 1];
return 0;
}