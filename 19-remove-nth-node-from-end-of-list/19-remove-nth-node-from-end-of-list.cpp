class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || head->next == NULL)return NULL;
        ListNode *first= head, *second = head;
        while(n--){
            first = first->next;
        }
        if(first == NULL)return head->next;
        while(first->next != NULL){
            first = first->next;
            second = second->next;            
        }
        second->next = second->next->next;
        return head;
    }
};