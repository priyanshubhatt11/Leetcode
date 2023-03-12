
class Solution {
public:
    class comp{
        public:
        bool operator()(ListNode* A, ListNode* B){
            return A->val > B->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode(0);   // dummy node
        ListNode* temp = head;
        priority_queue<ListNode* , vector<ListNode*>, comp> pq;
        for(auto node : lists){
            if(node!=NULL){
                pq.push(node);
            }
        }
      
        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();
            temp->next = node;
            temp = temp->next;
            if(node->next!= NULL){
                pq.push(node->next);
            }
        }
        return head->next; 
        
    }
};