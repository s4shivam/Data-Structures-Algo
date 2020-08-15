        1
       / \
      2   \
     / \   \
    4   5   \
       / \   3
      8   9 / \
           /   7
          6   / 
           \ 11
            10

#include <iostream>
#include<queue>
using namespace std;

class node
{
public:
  int data;
  node* left;
  node* right;
  node(int d)
  {
    data = d;
    node* left = NULL;
    node* right = NULL;
  }
};
node* newnode(int dt)
{
  node* temp = new node(dt);
  return temp;
}
void DFS(node* root){
  if(!root){
    return;
  }
  cout<<root->data<<" , ";
  if(root->left){
    DFS(root->left);
  }
  if(root->right){
    DFS(root->right);
  }
  return;
}

int main()
{
  node* root = newnode(1);
  root->left = newnode(2);
  root->right = newnode(3);
  root->left->left = newnode(4);
  root->left->right = newnode(5);
  root->right->left = newnode(6);
  root->right->right = newnode(7);
  root->left->right->left = newnode(8);
  root->left->right->right = newnode(9);
  root->right->left->right = newnode(10);
  root->right->right->left = newnode(11);
  DFS(root);
  return 0;
}
