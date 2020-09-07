#include <iostream>
using namespace std;

struct node{
int val;

node *next;
node *prev;

node(int x){
     val = x;
     next = NULL;
     prev = NULL;
}
};

struct queue{
     int sz;
     node *head;
     node *tail;

     queue(){
          sz = 0;
          head = NULL;
          tail = NULL;
     }
     void front(){
          if(head != NULL){
          cout<<head ->val<<endl;
          }
          else{
                cout<< "error"<<endl; 
          }
     }

     int size(){
return sz;
     }

     void pop(){
      if(head!=NULL){
           sz--;
           cout<< tail -> val<<endl;
           tail = tail -> next;
      }
       else{
                cout<< "error"<<endl;
       }
     }

     void clear(){
          head = NULL;
          tail = NULL;
          sz = 0;
     }

     void push(int x){
          node *n = new node(x);
          if(tail == NULL){
               head = tail = n;
          }
          else{
               tail->next = n;
               n -> prev = tail;
               tail = n;
          }
          sz++;
     }
};

int main(){
int x;
queue q;
string command;

while(cin>>command){
if(command == "push"){
     cin>>x;
q.push(x);
cout<<"ok"<<endl;
}

else if(command == "clear"){
q.clear();
}

else if(command=="front"){
q.front();
}
else if(command=="exit"){
     break;
}
else if(command=="pop"){
q.pop();
}
else if(command=="size"){
cout<<q.size()<<endl;
}
}
     return 0;
}