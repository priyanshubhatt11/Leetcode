class Solution {
public:
    vector<int> vec;
    int n;
    Solution(ListNode* head) {
        while(head!=NULL){
            vec.push_back(head->val);
            head = head->next;
        }
        n = vec.size();
    }
    
    int getRandom() {
        int x = rand()%n;
        return vec[x];
    }
};
