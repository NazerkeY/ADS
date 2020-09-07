#include <iostream>
using namespace std;
int main(){
     int n;
     int min1, min2, buffer;
     cin >> n;
     int a[n];
     for(int i = 0; i < n; i++){
          cin >> a[i];
     }

    if(a[0] < a[1]){
         min1 = 0;
         min2 = 1;
    }
    else{
         min1 = 1;
         min2 = 0;
    }

    for(int i = 2; i < n; i++){
         if(a[i] < a[min1]){
              min1 = buffer;
              min1 = i;
              if(a[buffer] < a[min2]) min2 = buffer;
         }
         else{
              if(a[i] < a[min2]) min2 = i;
         }
    }
          cout<< a[min1] << " " << a[min2]; 
}