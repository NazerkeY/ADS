#include <iostream>
using namespace std;
int main(){
int n;
cin>>n;
int num;

int cnt = 0;
int a[n];
for(int i=0; i<n; i++){
     cin>>a[i];
}
cin>>num;
for(int i=0; i<n; i++){
     if(num==a[i]){
          cnt++;
     }
}
cout<<cnt<<endl;
     return 0;
}