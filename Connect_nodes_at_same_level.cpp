#include <iostream>
#include<queue>
using namespace std;

struct node{
  	char data;
  	node* left;
  	node* right;
  	node* next;
};

node* CreateNode(char data){
	node* temp = new node;
  	temp->data = data;
  	temp->left = temp->right = temp->next = NULL;
  	return temp;
}

void ConnectNodes(node* root){
  if(root==NULL){
    return;
  }
  else{
    queue<struct node*> Q;
    Q.push(root);
    Q.push(NULL);
    while(!Q.empty()){
      struct node* t = Q.front();
      Q.pop();
      if(t!=NULL){
        t->next = Q.front();
        
        if(t->left){
          Q.push(t->left);
        }
        if(t->right){
          Q.push(t->right);
        }
      }
      else if (!Q.empty())  {
            Q.push(NULL);
      }
    }
  }
}
int main() {
  	node* root;
  	root = CreateNode('A');
  	root->left = CreateNode('B');
  	root->right = CreateNode('C');
  	root->left->left = CreateNode('D');
  	root->left->right = CreateNode('E');
  	root->right->left = CreateNode('F');
  	root->right->right = CreateNode('G');
  	root->left->left->right = CreateNode('H');
  	root->right->right->right = CreateNode('I');
  	ConnectNodes(root);
  	node* level0 = root;
  	while(level0 != NULL){
  		cout<<level0->data;
  		level0 = level0->next;
	}
	cout<<endl;
  	node* level1 = root->left;
  	while(level1!=NULL){
    	cout<<level1->data<< " ";
    	level1 = level1->next;
  	}
  	cout<<endl;
  	node* level2 = root->left->left;
  	while(level2!=NULL){
    	cout<<level2->data<< " ";
    	level2 = level2->next;
  	}
  	cout<<endl;
  	node* level3 = root->left->left->right;
  	while(level3!=NULL){
	    cout<<level3->data<< " ";
	    level3 = level3->next;
  	}
  	return 0;
}
