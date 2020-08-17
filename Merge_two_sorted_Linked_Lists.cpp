#include<iostream>
using namespace std;
class node
{public:
  int data;
  node* next;
  node(int d){
    data = d;
    next = NULL;
  }
};
node* createLL(int d)
{
  node* temp = new node(d);
    return temp;
}
void showLL(node* root){
  node* ptr = root;
  if(!root){
    return;
  }
  while(ptr){
    cout<<ptr->data<<" -> ";
    ptr = ptr->next;
  }
  return;
}
node* mergesortedLL(node* p,node* q){
  node* temp;
  if(p==NULL){
    return q;
  }
  if(q==NULL){
    return p;
  }
  if(p->data <= q->data){
    temp = p;
    temp->next = mergesortedLL(p->next,q);
  }
  if(p->data > q->data){
    temp = q;
    temp->next = mergesortedLL(p,q->next);
  }
  return temp;
}
int main()
{
  node *p,*q;
  node* f=NULL;
  p=createLL(10);
  p->next=createLL(50);
  p->next->next=createLL(70);
  p->next->next->next=createLL(90);
  p->next->next->next->next=createLL(100);
  q=createLL(20);
  q->next=createLL(30);
  q->next->next=createLL(40);
  q->next->next->next=createLL(60);
  q->next->next->next->next=createLL(80);
  showLL(p);
  cout<<endl;
  showLL(q);
  f = mergesortedLL(p,q);
  cout<<endl;
  showLL(f);
  return 0;
}
