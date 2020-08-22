SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* head) {
    if(!head || !head->next)
    {
        return head;
    }
    else{
        SinglyLinkedListNode* temp = head;
        while(temp->next){
            if(temp->data == temp->next->data){
                temp->next = temp->next->next;
            }
            else
                temp=temp->next;
        }
    }
    return head;
}
