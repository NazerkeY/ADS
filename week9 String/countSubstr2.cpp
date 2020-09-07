#include <iostream>
using namespace std;

int patSearch(char *pat, char *text){
     int M = pat.size();
     int N = text.length();

     //create lps[] that will hold the longest
     //prefix suffix values

     int lps[M];
     int j = 0; //index of pat[]

     computeLPSarray(pat, M, lps);

     int  i = 0;
     int res = 0;
     int next_i = 0;

     while(i < N){
          if(pat[j] == text[i]){
               j++;
               i++;
          }
          if(j == M){
               j = lps[j - 1];
               res++;
               if(lps[j] != 0)
               i = next_i++;
               j= 0;
          }

          else if(i < N && pat[j] != text[i]){
               if(j != 0)
               j = lps[j - 1];
               else
               i = i + 1;
          }
     }
     return res;
}

void computeLPSarray(char *pat, int M, int *lps){
     //len of the prev longest preff
     int len = 0;
     int i = 1;
     lps[0] = 0;

     while(i < M){
          if(pat[i] == pat[len]){
               len++;
               lps[i] = len;
               i++;
          }
          else{
               if(len != 0){
                    len = lps[len - 1];
               }
               else{
                    lps[i] = len;
                    i++;
               }
          }
     }
}

int main(){
     string s1, s2;
     cin >> s1 >> s2;
     cout << patSearch(s2, s1);
     return 0;
}