DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) {
    DoublyLinkedListNode* node = new DoublyLinkedListNode(data);
    if(!head){
        return NULL;
    }
    DoublyLinkedListNode* temp = head;
    DoublyLinkedListNode* before = NULL;
    if(data<temp->data){
        node->next = temp;
        temp->prev = node;
        return node;
    }
    while(temp->data<data){
        before = temp;
        if(temp->next){
            temp=temp->next;
        }
        else{
            temp->next = node;
            node->prev = temp;
            return head;
        }
    }
    node->prev = before;
    node->next=temp;
    before->next = node;
    temp->prev = node;
    return head;
}
