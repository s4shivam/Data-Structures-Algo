#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
	char data;
	struct node* left;
	struct node* right;
};
void PostOrder(struct node* root){
	if(!root){
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	cout<<root->data<<" ";
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
	
	PostOrder(root);
	return 0;
}
