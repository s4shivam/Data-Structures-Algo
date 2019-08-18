#include<iostream>
#include<queue>
using namespace std;
struct node{
	char data;
	struct node* left;
	struct node* right;
};
void LevelOrder(struct node* root){
	if(!root) return ;
	queue<struct node*> Q;
	Q.push(root);
	while(!Q.empty()){
		struct node * p = Q.front();
		cout<<p->data<<" ";
		Q.pop();
		if(p->left) {
			Q.push(p->left);
		}
		if(p->right){
			Q.push(p->right);
		}
	}
}
struct node* NewNode(char data)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->right = NULL;
	temp->left = NULL;
	return temp;
}
int main()
{
	struct node* root;
	root  = NewNode('a');		
								
	root->left  = NewNode('b');	
	root->right  = NewNode('c');
	
	root->left->left = NewNode('d'); 
	root->left->right = NewNode('e');
	root->right->left = NewNode('f');
	root->right->right = NewNode('g');	 
	
	root->left->left->left = NewNode('h');  
	root->right->right->left = NewNode('i'); 
	root->right->right->right = NewNode('j'); 
	LevelOrder(root);
	return 0;
}
