class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head, *fast = head;
        bool flag = false;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                flag = true;
                break;
            }
        }
        if(!flag)return NULL;
        
        fast = head;
        while(fast != slow){
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};