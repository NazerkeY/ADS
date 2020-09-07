//неубывающий массив
//0 1 2  3  4  5  6  7  8     [from 0 to 8]
//1 8 9 12 34 45 62 91 100
//нужно найти k=8;
//m =(l+r)/2 (the middle is 34 [element num 4])
//8<34, so we use left side
// if k>a[m], we use l = m+1; else r=m;
// in our case l=0 && r=4 => (0+4)/2 = 2. Now m =2; r=2, l=0 ; Now m = (0+2)/2 = 1, r=1, l=0;
#include <iostream>
using namespace std;

int bin_search(int *a, int n, int k){
     int l = 0;
     int r = n-1;
     while(l<r){
          int m = (l+r)/2;
          if(a[m]<k)
          l = m + 1;
          else
               r = m;   
     }
     if(a[r] == k){
          return r;
          return -1;
     }
}
int main(){
     int n, k;
     cin>>n>>k;
     int a[n];
     for(int i=0; i<n; i++){
          cin>>a[i];
     }
     int t = bin_search(a, n, k);
     cout<<t;

     return 0;
}