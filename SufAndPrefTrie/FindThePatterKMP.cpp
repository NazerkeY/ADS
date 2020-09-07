#include <iostream>
using namespace std;

void KMPSearch(char *txt, char *pattern){
int N = txt.size();
int M = patter.size();

int lps[M];

computeLPSArray(pattern, M, lps);
     int i;
     int j;
     while(i < N){
          if(pattern[j] == txt[i]){
               i++;
               j++;
          }
          if(j == M){
               cout << i - j;
               j = lps[J - 1];     
          }

          else if(i < N && pattern[j] != txt[i]){
               if(j != 0)
               j = lps[j - 1];
               else
               i = i + 1;
          }
     }
}

void computeLPSArray(char *pattern, int M, int *lps){
     int length = 0;
     lps[0] = 0;

     while(i < M){
          if(pattern[i] == lps[length]){
               length++;
               lps[i] = length;
               i++;
          }
     }
}

int main{
     return 0;
}