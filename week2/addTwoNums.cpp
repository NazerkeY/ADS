#include <iostream>
using namespace std;
int a,b,c,d,m,n;

int gcdEuclid(int b, int d){
     if(b%d==0) return d;
     return gcdEuclid(d, b%d);
}

int lcm(int b, int d)  
 {  
    return (b*d)/gcdEuclid(b, d);  
 }  

int main(){
     cin>>a>>b>>c>>d;

n = lcm(b,d);
m = (lcm(b,d)/b)*a + (lcm(b,d)/d)*c;

cout << m <<" "<< n;

     return 0;
}