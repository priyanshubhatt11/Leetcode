
class Solution {
public:
    ListNode*temp;
    void solve(ListNode* head,int &m, int n, bool &flag){
        if(head == NULL){
            flag = true;
            m = n/2;
            return;
        }
        solve(head->next, m, n+1, flag);
        //cout<<n<<" "<<m<<endl;
        if(flag == true && n == m){
            temp = head;
        }
        
    }
    
    ListNode* middleNode(ListNode* head) {
        bool flag = false;
        int m =0;
        solve(head, m,0, flag);
        return temp;
    }
};