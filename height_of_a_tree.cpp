#include <iostream>
#include<algorithm>
using namespace std;
class node{
  public:
  char data;
  node* left;
  node* right;
  node(char d){
    data = d;
    left = NULL;
    right = NULL;
  }
};
node* NewNode(char d)
{
  node* temp = new node(d);
  return temp;
}
int height(node* root)
{
  if(!root){return 0;}
  if(root->left==NULL && root->right==NULL){return 0;}
  int l,r;
  l=height(root->left);
  r= height(root->right);
  return 1+ max(l,r);
}
int main() {
  node* root;
	root = NewNode('a');
	root->left = NewNode('b');
  root->right = NewNode('c');
  root->left->left = NewNode('d');
  root->left->right = NewNode('e');
  root->left->right->left = NewNode('j');
  root->left->right->right = NewNode('k');
  root->left->left->left = NewNode('h');
  root->left->left->right = NewNode('i');
  root->left->left->right->left = NewNode('l');
  root->left->left->right->right = NewNode('m');root->left->left->right->right->left = NewNode('n');
  root->left->left->right->right->left->right = NewNode('o');
  cout<<height(root);
  return 0;
}
