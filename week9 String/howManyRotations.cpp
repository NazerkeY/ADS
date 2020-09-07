#include <bits/stdc++.h> 
using namespace std;

void  computeLPSarray(char *pat, int M, int *lps);

int KMPsearch(char *pat, char *text){
     int M = strlen(pat);
     int N = strlen(text);

     int lps[M];
     computeLPSarray(pat, M, lps);
     int i = 0;
     int j = 0;
     while(i < N){
          if(pat[j] == text[i]){
               j++;
               i++;
          }
          if(j == M){
               return i - j;
               j = lps[j - 1];
          }

          else if(i < N && pat[j] != text[i]){
               if(j != 0)
               j = lps[j - 1];
               else i = i + 1;
          }
     }
}

void computeLPSarray(char *pat, int M, int *lps){
     int len = 0;
     lps[0] = 0;
     int i = 1;
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
                    lps[i] = 0;
                    i++;
               }
          }
     }
}

int countRotations(string s){
     string s1 = s.substr(1, s.size() - 1) + s;
     char pat[s.length()], text[s1.length()];

     strcpy(pat, s.c_str());
     strcpy(text, s1.c_str());

     return 1 + KMPsearch(pat, text);
}
int main(){

     string s1;
     cin >> s1;
     cout<< countRotations(s1);
     return 0;
}