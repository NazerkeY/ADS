#include <iostream>
using namespace std;

struct stack{
int arr[100];
int begin;

stack(){
 begin=0;
}

void push(int x){
     arr[begin] = x;
     begin++;
}

int pop(){
     int num = arr[begin-1];
     begin--;
     return num;
}

int back(){
     return arr[begin-1];
}

int size(){
return begin;
}
 
string clear(){
     begin=0;
     return "ok";
}
};

int main(){
string command;
int x;
stack s;

while(cin >> command){
     if(command == "push"){
          cin>>x;
          s.push(x);
          cout<<"ok"<<endl;
     }
 else if(command=="pop"){
          cout<< s.pop() <<endl;
          }
          else if(command=="back"){
           cout<<s.back()<<endl;
          }
          else if(command=="size"){
          cout<< s.size() <<endl;
          }
          else if(command=="clear"){
           cout<<s.clear()<<endl;
          }
          else if(command == "exit"){
               cout << "bye!"<<endl;
               break;
          }
     }

     return 0;
}