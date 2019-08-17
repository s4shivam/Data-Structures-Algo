#include<stdlib.h>
#include<iostream>
using namespace std;
struct node{
	int data;
	struct node* link;
};
struct node* ROOT= NULL;
void InsertNode(int n){
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = n;
	temp->link = NULL;
	if(ROOT == NULL){
		ROOT = temp;
	}
	else{
		struct node* ptr;
		ptr = ROOT;
		while(ptr->link!=NULL){
			ptr = ptr->link;
		}
		ptr->link = temp;
	}
}
void Traverse(){
	struct node* temp;
	if(ROOT==NULL){
		cout<<"\nList is Empty\n";
	}
	else{
		temp = ROOT;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp = temp->link;
		}
	}
}
void Reverse(){
	struct node *temp,*next=NULL,*prev=NULL;
	temp = ROOT;
	while(temp!=NULL){
		next = temp->link;
		temp->link = prev;
		prev = temp;
		temp = next;
	}
	ROOT = prev;
}
int main(){
	InsertNode(30);
	InsertNode(50);
	InsertNode(70);
	InsertNode(80);
	InsertNode(100);
	Traverse();
	cout<<endl;
	Reverse();
	Traverse();
	return 0;
}
