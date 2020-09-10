#include<iostream>
using namespace std;
class Node
{
  public:
  int data;
  Node* next;
  Node(int x){
    data = x;
    next = NULL;
  }
};
Node* MergeList(Node* l1,Node* l2){
  Node* start = new Node(-1);
  Node* last = start;
  while(l1 && l2){
    if(l1->data < l2->data){
      last->next = l1;
      last = l1;
      l1 = l1->next;
    }
    else{
      last->next = l2;
      last = l2;
      l2 = l2->next;
    }
  }
  if(l1){
      last->next = l1;
  }
  if(l2){
      last->next = l2;
  }
  return start->next;
}
void printList(Node* n) 
{ 
    while (n != NULL) { 
        cout << n->data << " "; 
        n = n->next; 
    } 
    cout<<endl;
}
int main()
{
  Node* l1 = new Node(2);
  l1->next = new Node(4);
  l1->next->next = new Node(7);
  l1->next->next->next = new Node(9);
  printList(l1);
  Node* l2 = new Node(3);
  l2->next = new Node(5);
  l2->next->next = new Node(6);
  l2->next->next->next = new Node(8);
  l2->next->next->next->next = new Node(9);
  l2->next->next->next->next->next = new Node(11);
  printList(l2);
  Node* l3 = MergeList(l1,l2);
  printList(l3);
  return 0;
}
