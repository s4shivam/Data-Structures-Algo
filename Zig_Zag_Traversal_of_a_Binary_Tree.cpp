#include <iostream>
#include<stack>
using namespace std;
struct node
{
  char data;
  struct node* left;
  struct node* right;
};
struct node* NewNode(char c)
{
  struct node* temp = (struct node*)malloc(sizeof(struct node));
  temp->data = c;
  temp->right = NULL;
  temp->left = NULL;
  return temp;
}
void Inorder(struct node* root)
{
  if(root)
  {
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
  }
  return ;
}
void ZigZag(struct node* root){
  stack<struct node*> s1;
  stack<struct node*> s2;
  s1.push(root);
  while(!s1.empty() || !s2.empty())
  {
    while(!s1.empty())
    {
      struct node* p = s1.top();
      cout<<p->data<<" ";
      s1.pop();
      if(p->left){
        s2.push(p->left);
      }
      if(p->right){
        s2.push(p->right);
      }
    }
    while(!s2.empty())
    {
      struct node* p = s2.top();
      cout<<p->data<<" ";
      s2.pop();
      if(p->right){
        s1.push(p->right);
      }
      if(p->left){
        s1.push(p->left);
      }
      
    }
  }
}
int main()
{
  struct node* root = NULL;
  root = NewNode('a');
  root->left = NewNode('b');
  root->right = NewNode('c');
  root->left->left = NewNode('d');
  root->left->right = NewNode('e');
  root->right->left = NewNode('f');
  root->right->left->right = NewNode('h');
  root->right->right = NewNode('g');
  Inorder(root);
  cout<<endl;
  ZigZag(root); 
  return 1;
}
