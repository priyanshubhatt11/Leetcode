class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;
        
        while(head){
            while(!st.empty() && st.top()->val < head->val){
                st.pop();
            }
            st.push(head);
            head = head->next;
        }
        
        // reversing stack
        stack<ListNode*> s;
        while(!st.empty()){
            s.push(st.top());
            st.pop();
        }
        
        head = s.top();
        ListNode*temp = s.top();
        while(!s.empty()){
            temp->next = s.top();
            temp = temp->next;
            s.pop();
        }
        temp->next = NULL;
        return head;
        
        
    }
};