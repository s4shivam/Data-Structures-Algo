/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)
        {
            return NULL;
        }
        if(!head->next && n==1){
            return NULL;
        }
        
        ListNode* prev = head;
        ListNode* prevofprev = prev; //if n=1 then we have to remove the last element
        ListNode* forward = head;
        int count = n-1;
        while(count--){
            forward =  forward->next;
        }
        while(forward->next){
            forward = forward->next;
            prevofprev = prev;
            prev = prev->next;
        }
        if(n==1){
            prevofprev->next = NULL;
        }
        else{
            prev->val = prev->next->val;
            prev->next = prev->next->next;
        }
        return head;
        
    }
};
