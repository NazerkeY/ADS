#include <iostream>
using namespace std;
//8 1 6 1 6 8 9 3 3 7
//1 1 3 3 6 6 7 8 8 9 

//0 1 2 3 4 5 6 7 8 9 
//0 2 0 2 0 0 2 1 2 1 - cnt;

int n, k;
int b[10];

int main(){
     cin >> n;
     for(int i = 0; i < n; i++){
          cin >> k;
          b[k]++;
     }
//в b[i] мы храним сколько раз встречается число в массиве
//выводим i 'j' раз
     for(int i = 0; i< 10; i++){
          for(int j = 0; j < b[i]; j++)
          cout << i << " ";
     }
     return 0;
}