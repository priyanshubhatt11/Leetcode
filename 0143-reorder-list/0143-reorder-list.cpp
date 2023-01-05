class Solution {
public:
    
    ListNode*curr, *temp;
    
    void solve(ListNode* node){
        if(node == NULL)return;
        solve(node->next);
        curr->next = node;
        node->next = temp;
        curr = temp;
        temp = temp->next;
    }
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL)return;
        ListNode* mid = head;
        temp = head;
        while(temp!= NULL && temp->next){
            temp = temp->next->next;
            mid = mid->next;
        }
        
        curr = head;
        temp = curr->next;
        solve(mid);
        temp->next = NULL;
        
    }
};