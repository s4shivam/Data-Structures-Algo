#include <iostream>
#include<stdlib.h>
using namespace std;

struct node
{
  int data;
  struct node* left = NULL;
  struct node* right = NULL;
};
struct node* root = NULL;

struct node* CreateNode(int d)
{ 
  struct node* temp = (struct node*)malloc(sizeof(struct node));
  temp->data = d;
  return temp;

}
void mirror(struct node* ptr)
{
  if(ptr==NULL){
    return;
  }
  else{
      swap(ptr->left,ptr->right);
      mirror(ptr->left);
      mirror(ptr->right);
  }
}
void Inorder(struct node* t){
  if(t==NULL){
    return;
  }
  else{
    Inorder(t->left);
    cout<<t->data<<" ";
    Inorder(t->right);
  }
}
void swap(struct node* L,struct node* R)
{
  struct node* temp1;
  temp1 = L->left;
  L->left = L->right;
  L->right = temp1;
}
int main()
{
  struct node* root = CreateNode(1);
  root->left = CreateNode(2);
  root->left->left = CreateNode(4);
  root->left->right = CreateNode(5);
  root->right = CreateNode(3);
  root->right->right = CreateNode(7);
  root->right->left = CreateNode(6);
  Inorder(root);
  cout<<endl;
  mirror(root);
  Inorder(root);
  return 0;
}
