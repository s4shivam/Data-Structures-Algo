#include <iostream>
#include<stdlib.h>
using namespace std;
struct node{
  int data;
  struct node* next;
};
struct node* ROOT = NULL;

void InsertNode(int n){
  struct node* temp;
  temp = (struct node*)malloc(sizeof(struct node));
  temp->data = n;
  temp->next = NULL;
  if(ROOT == NULL){
    ROOT = temp;
  }
  else{
    struct node*  ptr;
    ptr = ROOT;
    while(ptr->next!= NULL){
      ptr = ptr -> next;
    }
    ptr->next = temp;
  }  
}
void Traverse(){
  if(ROOT==NULL){
    cout<<"The List is Empty";
  }
  else{
    struct node* temp;
    temp = ROOT;
    while(temp!= NULL){
      cout<<temp->data<<" ";
      temp = temp->next;
    }
  }
}
void DeleteNode(){
  struct node* temp;
  if(ROOT==NULL){
    cout<<"List is Empty :/"<<endl;
  }
  else{
    temp = ROOT;
    ROOT = ROOT -> next;
    free(temp);    
  }
}
int main() {
  cout<<"1 . Insert\n";
  cout<<"2 . Delete\n";
  cout<<"3 . View\n";
  cout<<"4 . quit\n";
  while(1){
    cout<<"\nEnter choice\n";
    int x;
    cin>>x;
    switch(x)
    {
      case 1:
        int i;
        cout<<"Enter the element :";
        cin>>i;
        InsertNode(i);
        break;
      case 4:
        exit(1);
      case 2:
        DeleteNode();
        cout<<"\nDeleting first "<<endl;
        break;
      case 3:
        Traverse();
        break;
      default:
        cout<<"Wrong choice >_<"<<endl;
        break;
    }
  }
  return 0;
}
