int listlength(SinglyLinkedListNode* head){
    SinglyLinkedListNode* temp = head;
    int len = 0;
    while(temp){
        len++;
        temp= temp->next;
    }
    return len;
}
int findMergeNode(SinglyLinkedListNode* p, SinglyLinkedListNode* q) {
    int l1 = listlength(p);
    int l2 = listlength(q);
    if(l1>l2)
    {
        int diff = l1-l2;
        while(diff--){
            p = p->next;
        }
    }
    else{
        int diff = l2-l1;
        while(diff--){
            q = q->next;
        }
    }
    while(p!=NULL  && q!=NULL)
    {
        if(p==q){
            return p->data;
        }
        p = p->next;
        q = q->next;
    }
  return 0;
}
