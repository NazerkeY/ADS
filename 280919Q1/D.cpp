#include <iostream>
using namespace std;
 int num;
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

struct dequeue{
     int sz;
     node *head;
     node *tail;

     dequeue(){
          sz = 0;
          head = NULL;
          tail = NULL;
     }
     void front(){
          if(head != NULL){
          cout<<head ->val<<endl;
          head = head->next;
          }
     }

     void back(){
          if(tail!=NULL){
               cout<<tail->val<<endl;
               tail = tail->prev;
          }
     }


void push_front(int x){
     node *n = new node(x);
     if(head == NULL){
          head = tail = n;
     }
     else{
          head->prev = n;
          n->next = head;
          head = n;
     }
     sz++;
}
     int size(){
return sz;
     }

//      void printRev(){
//         node *cur = tail;
//         while(cur!=NULL){
//              cout<<cur->val;
//              cur = cur->prev;
//         }
//         cout<<endl;
//    }

     void push_back(int x){
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
dequeue q;
string command;

cin>>num;
for(int i=0; i<num; i++){
while(cin>>command){
if(command == "push_back"){
     cin>>x;

cout<<q.push_back(x)<<endl;
}
else if(command == "push_front"){
     cin>>x;
     cout<<q.push_front(x)<<endl;
}

// else if(command == "reverse"){
//      q.printRev();
// }
if(sz == 0){
     cout<<";(";
}

else if(command=="front"){
q.front();
}
else if(command=="exit"){
     break;
}
else if(command=="back"){
q.back();
}
}
}
     return 0;
}