#include <iostream>
#include<stdlib.h>
using namespace std;
struct node
{
  int data;
  struct node* link;
};
struct expressnode{
  int data;
  struct expressnode* link;
  struct node* down;
};
int length=0;
struct node* root = NULL;
struct expressnode* expressroot = NULL;
void insertnode(){
  struct node* temp = (struct node*)malloc(sizeof(struct node));
  cout<<"ENter the element :";
  cin>>temp->data;
  temp->link = NULL;
  if(root==NULL){
    struct expressnode* uptemp = (struct expressnode*)malloc(sizeof(struct expressnode));
    root = temp;
    expressroot = uptemp;
    uptemp->data = temp->data;
    uptemp->link = NULL;
    uptemp->down = temp;
    length++;
  }
  else{
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr = root;
    while(ptr->link!=NULL){
      ptr = ptr->link;
    }
    ptr->link = temp;
    length++;
    if(length % 5 == 0){
      struct expressnode* tempup = (struct expressnode*)malloc(sizeof(struct expressnode));
      tempup->data = temp->data;
      tempup->link = NULL;
      tempup->down = temp;
      struct expressnode* exp_ptr;
      exp_ptr = expressroot;
      while(exp_ptr->link != NULL){
        exp_ptr = exp_ptr->link;
      }
      exp_ptr->link = tempup;
    }
  }
}
void Iteratedown(){
  struct node* ptr;
  ptr = root;
  while(ptr!=NULL){
    cout<<ptr->data<<" ";
    ptr = ptr->link;
  }
}
void Iterateup(){
  struct expressnode* ptr;
  ptr = expressroot;
  while(ptr!=NULL){
    cout<<ptr->data<<" ";
    ptr = ptr->link;
  }
}
int main(){
  while(1){
    cout<<"Enter data? :";
    char ans;
    cin>>ans;
    if(ans=='y'||ans=='Y'){
      insertnode();
    }
    else{
      break;
    }
  }
  cout<<endl<<"main list"<<endl;
  Iteratedown();
  cout<<endl<<"express list"<<endl;
  Iterateup();
  return 0;
}

