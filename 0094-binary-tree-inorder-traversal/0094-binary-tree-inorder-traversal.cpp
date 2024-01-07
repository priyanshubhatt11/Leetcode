
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == NULL)return {};
        stack<TreeNode*> st;
        vector<int> ans;
        st.push(root);
        while(!st.empty()){
            TreeNode * temp = st.top();
            
            if(temp->left != NULL){
                st.push(temp->left);
                temp->left = NULL;
            }
            else{
                ans.push_back(temp->val);
                st.pop();
                if(temp->right != NULL)st.push(temp->right);
            }
        }
        return ans;
    }
};