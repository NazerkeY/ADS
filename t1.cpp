#include<iostream>
#include <queue>

using namespace std;

struct myqueue{
    int arr[100];
    int begin;
    int end;
    int sum;

    myqueue(){
        begin=0;
        end=0;
        sum=0;
    }

    void push(int x){
        arr[end] = x;
        end++;
    }

    int pop(){
    int num = arr[begin];
    begin++;
    cout<< num;
    
    }

    int front(){
        return arr[begin];
    }

    int size(){
        return end - begin;
    }

    string clear(){
        end=0;
        begin=0;
        return "ok";
    }

};
int main(){

     string command;
     int x;
     myqueue q;

     while(cin >> command){
          if(command == "push"){
               cin >> x;
               q.push(x);
               cout << "ok" <<endl;
          }
          else if(command=="pop"){
          cout<< q.pop() <<endl;
          }
          else if(command=="front"){
           cout<<q.front()<<endl;
          }
          else if(command=="size"){
          cout<< q.size() <<endl;
          }
          else if(command=="clear"){
           cout<<q.clear()<<endl;
          }
          else if(command == "exit"){
               cout << "bye!"<<endl;
               break;
          }
     }

     return 0;
}