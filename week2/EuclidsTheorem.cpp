#include <iostream>
using namespace std;
int Euclid(int a, int b){
          if(a%b==0) return b;
          return Euclid(b, a % b);
     }
int main(){
     int a,b;
     cin>>a>>b;
    int res = Euclid(a,b);
     cout<<res;
     return 0;
}