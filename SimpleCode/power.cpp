#include <iostream>
using namespace std;
int myPow(int a, int n){
     if(n==0) return 1;
     if(n==1) return a;
     int res = myPow(a, n/2);
     if( n% 2 == 0)
     return res * res;
     return res * res *a;
}
int main(){
     int a,b;
     cin>>a>>b;
     cout<<myPow(a,b);   
     return 0;
}