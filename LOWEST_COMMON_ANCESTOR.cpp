#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
	char data;
	struct node* left;
	struct node* right;
};
struct node* LCA(struct node* root,char l,char r)
{
	if(root==NULL) return NULL;
	if(root->data == l ||root->data==r) return root;
	struct node* left1;
	struct node* right1;
	left1 = LCA(root->left,l,r);
	right1 = LCA(root->right,l,r);
	if(left1!=NULL && right1!=NULL) return root;
	else return(left1?left1:right1);
}
struct node* NewNode(char data)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
int main(){
	struct node* root;
	root = NewNode('a');
	root->left = NewNode('b');
	root->right = NewNode('c');
	root->left->left = NewNode('d');
	root->left->right = NewNode('e');
	root->right->left = NewNode('f');
	root->right->right = NewNode('g');
	root->left->left->left = NewNode('h');
	root->left->left->right = NewNode('i');
	root->left->left->right->left = NewNode('m');
	root->left->left->right->right = NewNode('n');
	root->left->right->left = NewNode('r');
	root->left->right->right = NewNode('s');
	
	struct node* answer = LCA(root,'n','f');
	cout<<answer->data;
	return 0;
}
