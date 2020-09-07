#include <iostream>
using namespace std;

int n;
int cnt=0;
int lineSearch(int a[], int num){
for(int i=0; i<n; i++){
     if(a[i]==num) {
     return i;
     }
else{ 
   return -1;
   }
}
}

int main(){
     int num, a[n];
     cin>>n;
     cin>>num;
     for(int i=0; i<n; i++){
          cin>>a[i];
     }
     if(lineSearch(a, num)==-1){
     cout<<"NOPE";
     }
     else{ 
     cout<<"YEAP"<<lineSearch(a,num);
     }
     
     return 0;
}