/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::solve(ListNode* A, int B) {
    if (!A){
        return -1;
    }
    int len = 0;
    int lenWeWant = 0;
    ListNode* slow = A;
    ListNode* fast = A;
    while(fast!=NULL  && fast->next!=NULL){
        len++;
        slow = slow->next;
        fast = fast->next->next;
    }
    lenWeWant = len - B;
    if(lenWeWant < 0){
        return -1;
    }
    ListNode* temp = A;
    while(lenWeWant--){
        temp = temp->next;
    }
    return temp->val;
}
