#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
	int data;
	struct node* left;
	struct node* right;
};
struct node* newnode(int d){
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = d;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
int NoOfNodes(struct node* ptr){
	if(ptr!=NULL){
		return (1+NoOfNodes(ptr->left) + NoOfNodes(ptr->right));
	}
	else
		return 0;
}
int main(){
	struct node* root = newnode(5);
	root->left = newnode(3);
	root->left->left = newnode(2);
	root->left->right = newnode(4);
	root->right = newnode(8);
	root->right->right = newnode(9);	
	root->right->left = newnode(7);
	root->right->right->right = newnode(20);	
	int no;
	no = NoOfNodes(root);
	cout<<"Nodes are :"<<no;
	return 0;
}
