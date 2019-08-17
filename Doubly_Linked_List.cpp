#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
	int data;
	struct node* left;
	struct node* right;
};
struct node* root;
void InsertNode(){
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	cout<<"Enter the element :";
	cin>>temp->data;
	temp->left = NULL;
	temp->right = NULL;
	if(root == NULL){
		root = temp;
	}
	else{
		struct node* ptr;
		ptr = root;
		while(ptr->right != NULL)
			ptr = ptr->right;
		temp->left = ptr;
		ptr->right = temp;
	}
}
void InsertAtBegin(){
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	cout<<"Enter the Element. :";
	cin>>temp->data;
	temp->left = NULL;
	temp->right = NULL;
	if(root == NULL){
		root = temp;
	}
	else{
		temp->right = root;
		root->left = temp;
		root = temp;
	}
}

void Traverse(){
	struct node* ptr;
	ptr = root;
	if(root == NULL){
		cout<<"The List is Empty. \n";
	}
	else{
		while(ptr!=NULL){
			cout<< ptr->data <<" ";
			ptr = ptr->right;
		}
	}
}
void DeleteNode(){
	struct node *cur,*prev;
	if(root == NULL){
		cout<<"The list is already empty\n";
	}
	else{
		cur = root;
		while(cur->right!=NULL) cur = cur->right;
	}
	prev = cur->left;
	prev->right = NULL;
	cur->left = NULL;
	cout<<"The Deleted Element is : "<<cur->data<<" .\n";
	free(cur);
	cout<<"The list now is : ";
	Traverse();	
}
int main(){
  cout<<"1 . Insert\n";
  cout<<"2 . Insert at begin\n";
  cout<<"3 . Delete\n";
  cout<<"4 . View\n";
  cout<<"5 . quit\n";
  while(1){
    cout<<"\nEnter choice\n";
    int x;
    cin>>x;
    switch(x)
    {
    case 1:
        InsertNode();
        break;
    case 2:
        InsertAtBegin();
        break;
  	case 3:
    	DeleteNode();
    	break;
    case 4:
        Traverse();
        break;
    case 5:
    		exit(1);
    		
    default:
        cout<<"Wrong choice >_<"<<endl;
        break;
    }
  }
	return 0;
}
