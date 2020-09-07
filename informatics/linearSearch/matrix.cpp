#include <iostream>
using namespace std;
int main(){
     int n,m;
     int cnt = 0;
     cin >> n >> m;
     int a[n][m];
     int min = 10000000;
     int max = -10000000;
     for(int i = 0; i < n; i++){
          for(int j = 0; j < m; j++){
               cin >> a[i][j];
          }
     }

     for(int i = 0; i < n; i++){
          for(int j = 0; j < m; j++){
               if(a[i][j] < a[i][i]){
                    min = a[i][j];
               }
               if(a[i][j] > a[j][j]){
                    max = a[i][j];
               }
          }
          if(min == max){
               cnt++;
          }
     }
     cout << cnt;
}