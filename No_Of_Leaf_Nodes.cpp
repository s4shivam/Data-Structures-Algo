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
int NoOfLeafNodes(struct node* ptr){
	if(ptr==NULL){
		return 0;
	}
	if(ptr->left==NULL && ptr->right==NULL){
		return 1;
	}
	else{
		return (NoOfLeafNodes(ptr->left) + NoOfLeafNodes(ptr->right));
	}
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
	no = NoOfLeafNodes(root);
	cout<<"No of Leaf Nodes are :"<<no;
	return 0;
}
