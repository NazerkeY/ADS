#include <iostream>
using namespace std;
int n, k;
int b[10];

//считает элементы и сохраняет в массив, выводит их столько раз, сколько они встречаются в массиве.
//k - index
int main(){
     cin >> n;
     for(int i = 0; i < n; i++){
          cin >> k;
          b[k]++;
     }

     for(int i = 0; i < 10; i++)
     for(int j = 0; j < b[i]; j++)
     cout << i << " ";
}