#include <bits/stdc++.h>
using namespace std;
int num;
int main(){

    cin >> num;
    queue<int> queue;
    for(int i = 0; i < num; i++){
        int limit;
        cin >> limit;
        queue.push(limit);
        while(queue.front() < limit-3000){
          queue.pop();
    }
        cout << queue.size() << " ";
    }
  return 0;
}
