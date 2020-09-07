#include <iostream>
using namespace std;

iny a[1000];
int n;

void quickSort(int l, int r){
     int i = l;
     int j = r;
     int p = a[(l + r) / 2];

     while(i < j){
          while (a[i] < p){
               i++;
          }
          while(a[j] > p){
               j++;
          }
          if (i <= j){
               swap(a[i], a[j]);
               i++;
               j++;
          }
     }
}