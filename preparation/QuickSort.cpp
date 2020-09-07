#include <iostream>
//91 65 3 84 12 32 16  1  50  23
//0  1  2  3  4  5  6  7   8   9
//Выбираем пивот, делим массив на два: первая часть больше или равен, вторая часть меньше или равен
using namespace std;

int a[1000];
int n;
void quickSort(int l, int r){
     int i = l;
     int j = r;
     int p = a[(l+r)/2];
     while(i < j){
          while(a[i] < p) i++;
          while(a[j] > p) j--;
          if(i <= j){
               swap(a[i], a[j]);
               i++;
               j--;
          }
     }
     if(l < j)
     quickSort(l,j);
     if(i < r)
     quickSort(i, r);
}

int main(){
     cin >> n;
     for(int i = 0; i < n; i++){
          cin >> a[i];
     }
     quickSort(0, n - 1);

     for(int i = 0; i< n; i++){
          cout << a[i] << " ";
     }
     return 0;
}