Node * removeDuplicates( Node *head) 
{
 // your code goes here
 unordered_map<int,int> M;
  Node* temp = head;
  Node* prev = head;
  while(temp){
    if(M.find(temp->data)!=M.end()){
      //cout<<"found "<<temp->data<<" in map"<<endl;
      prev->next =  prev->next->next;
      temp = temp->next;
    }
    else{
      //cout<<"inserting "<<temp->data<<" in the map"<<endl;
      M[temp->data]++;
      prev = temp;
      temp = temp->next;
    }
  }
  return head;
}
