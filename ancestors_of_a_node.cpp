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
int ancestors(node* root,char c)
{
  if(!root){return 0;}
  if(root->data == c){
    cout<<c;
    return 1;
  }
  int l,r;
  l = ancestors(root->left,c);
  r = ancestors(root->right,c);
  if(l||r){
    cout<<" , "<<root->data;
    return 1;
  }
  return 0;
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
  return ancestors(root,'o');
  
}
