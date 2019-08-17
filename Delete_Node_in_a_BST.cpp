#include <iostream>
#include<stdlib.h>
using namespace std;
struct node
{
  int data;
  struct node* left;
  struct node* right;
};
struct node* NewNode(int n)
{
  struct node* temp;
  temp =(struct node*)malloc(sizeof(struct node));
  temp->data = n;
  temp->right = NULL;
  temp-> left = NULL;
  return temp;
}
void Inorder(struct node* ptr){
  if(ptr){
    Inorder(ptr->left);
    cout<<ptr->data<<" ";
    Inorder(ptr->right);
  }
  return;
}
struct node* findMax(struct node* ptr){
  if(ptr==NULL){
    return ptr;
  }
  else{
    //struct node* ptr1 = ptr;
    while(ptr->right!=NULL){
      ptr = ptr->right;//ptr = ptr1;
      //ptr1=ptr1->right;
    }
    cout<<"Max is :"<<ptr->data<<endl;
  }
  return ptr;
}
struct node* Deletion(struct node* root,int data){
  struct node* temp;
  if(root==NULL){
    return root;
  }
  else if(data > root->data){
      cout<<"Here"<<endl;
      cout<<root->right->data<<endl;
      root->right = Deletion(root->right,data);
    }
  else if(data < root->data){
      root->left = Deletion(root->left, data);
      }
    else{
      if(root->left!=NULL && root->right!=NULL){
        temp = findMax(root->left);
        root->data = temp->data;
        root->left = Deletion(root->left, root->data);
      }
      else{
        temp = root;
        if(root->left==NULL){
          root=root->right;
        }
        if(root->right==NULL){
          root=root->left;
        }
        free(temp);
      }
    }
  return(root);
}
int main() {
  struct node* root = NULL;
  root = NewNode(4);
  root->left = NewNode(2);
  root->left->left = NewNode(1);
  root->right = NewNode(8);
  root->right->right = NewNode(9);
  root->right->left = NewNode(5);
  root->right->left->right = NewNode(7);
  root->right->left->right->left = NewNode(6);
  cout<<"INorder Before Deletion is:\n";
  Inorder(root);
  root = Deletion(root,8);
  cout<<"Inorder After Deletion:\n";
  Inorder(root);
}
