#include <iostream>
using namespace std;

struct node{
int  data;
node *pNext;
node *pPrev;

 node(int x){
     data = x;
     pNext = NULL;
     pPrev = NULL;
}
};

struct doubleLinkedList{
     node *head;
     node *end;

   doubleLinkedList(){
        head = NULL;
        end = NULL;
   }
   void push(int x){
        node *n = new node(x);
     if(end == NULL){
          head = end = n;
     }
     else{
          end -> pNext = n;
          n -> pPrev = end;
          end = n;
     }
   }

   void print(){
     node *cur = head;
     while(cur!=NULL){
          cout<<cur->data<<"->";
          cur = cur->pNext;
          if(cur == NULL){
               cout<<"NULL";
          }
     }
     cout<<endl;
   }

   void printRev(){
        node *cur = end;
        while(cur!=NULL){
             cout<<cur->data<<"<-";
             cur = cur->pPrev;
             if(cur == NULL){
                  cout<< "NULL";
             }
        }
        cout<<endl;
   }
};

int main(){
     int a[] = {1,2,3,4,5};
     doubleLinkedList lst;
     for(int i=0; i<sizeof(a)/sizeof(int); i++){
          lst.push(a[i]);
     }
     lst.print();
     lst.printRev();
     return 0;
}