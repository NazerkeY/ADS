#include <bits/stdc++.h>
using namespace std;
main() {
        string s;
        cin >> s;
        stack <char> st;
        map <char, char> mp;
        mp['{'] = '}';
        mp['['] = ']';
        mp['('] = ')';
        for(int i = 0; i < s.size(); i ++) {
                if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                        st.push(s[i]);
                else {
                        if(st.empty() || (st.size() && s[i] != mp[st.top()])) {
                                puts("NO");
                                return 0;
                        }
                        else
                                st.pop();
                }
        }
        if(!st.size())
        puts("YES");
        else
        puts("NO");
        return 0;
}


/* 
#include <iostream>
#include <stack>

using namespace std;

int main(){

    string s;
    cin >> s;

    stack<char> st;
    bool ok = true;

    for(int i = 0; i < s.size(); ++i){
        if(s[i] == '('){
            st.push(s[i]);
        }else if(s[i] == ')'){
            if(st.size() > 0){
                st.pop();
            }else{
                ok = false;
                break;
            }
        }
    }

    if(st.size() > 0 || ok == false){
        cout << "no";
    }else{
        cout << "ok";
    }


    return 0;
}
 */