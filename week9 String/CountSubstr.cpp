//naz //asddnazdksssnazassaz => 2
#include <iostream>
#include <vector>
//algorithm O(N*M);
using namespace std;

int countSubstr(string &substr, string &text){
     int M = substr.length();
     int N = text.length();
     int res = 0;

     int j;
     for(int i = 0; i <= N - M; i++){
     for(j = 0; j < M; j++)
          if(text[i + j] != substr[j])
          break;

          if(j == M){
               res++;
               j = 0;
          }
     }
     return res;
}
int main(){
     string s1, s2;
     cin >> s1 >> s2;
     cout<<countSubstr(s1, s2);
     return 0;
}