
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* temp = root;
        
        while(!st.empty() || temp != NULL){
            
            if(temp){
                st.push(temp);
                temp = temp->left;                
            }
            else{
                temp = st.top();
                st.pop();
                ans.push_back(temp->val);
                
                temp = temp->right;
            }
        }
        return ans;
    }
};