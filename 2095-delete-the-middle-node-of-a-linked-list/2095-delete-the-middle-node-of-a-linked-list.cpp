
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        int c=0;
        ListNode *temp = head;
        while(temp!=NULL){
            c++;
            temp = temp->next;
        }
        
        c = c/2;
        c--;
        if(c<0)return NULL;
        temp = head;
        while(c!=0){
            temp = temp->next;
            c--;
        }
        temp->next = temp->next->next;
        return head;
    }
};