#include <iostream>
using namespace std;

struct node{
     int data;
     node *pNext;

     node(int x){
          data = x;
          pNext = NULL;
     }
};

struct linkedList{
     node *head;
     node *end;

     linkedList(){
          head = NULL;
          end = NULL;
     }

     void push(int x){
          if(end == NULL){
               end = new node(x);
               head = end;
          }
          else{
               node *n = new node(x);
               end -> pNext = n;
               end = n;
          }
     }
     void print(){
          node *cur = head;
          while(cur != NULL){
               cout<<cur -> data << "->";
               cur = cur -> pNext;
               if(cur == NULL){
                    cout<<"NULL";
               }
          }
          cout<<endl;
     }
     }      
};

int main(){
     int a[]={1, 2, 3, 4, 5};
     linkedList lst;
     for(int i=0; i<sizeof(a)/sizeof(int); i++){
          lst.push(a[i]);
     }
     lst.print();
     return 0;
}