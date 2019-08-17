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
int NoOfFullNodes(struct node* ptr){
	if(ptr==NULL){
		return 0;
	}
	if(ptr->left==NULL && ptr->right==NULL){
		return 0;
	}
	else{
		return (NoOfFullNodes(ptr->left) + NoOfFullNodes(ptr->right)+ ((ptr->left!=NULL && ptr->right!=NULL)?1:0) );
	}
}
int main(){
	struct node* root = newnode(10);
	root->left = newnode(3);
	root->right = newnode(18);
	root->right->left = newnode(15);
	root->right->left->right = newnode(16);	
	root->right->left->left = newnode(13);	
	int no;
	no = NoOfFullNodes(root);
	cout<<"Nodes are :"<<no;
	return 0;
}
