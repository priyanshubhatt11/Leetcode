class Solution {
public:
    
    TreeNode* prev = NULL;
    
    void flatten(TreeNode* root) {
//         if(root == NULL)return;
        
//         flatten(root->right);
//         flatten(root->left);
        
//         root->right = prev;
//         root->left = NULL;
        
//         prev = root;
        
        
        //      OR
        
        if(root == NULL)return;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* temp = st.top();
            st.pop();
            if(temp->right){
                st.push(temp->right);
            }
            if(temp->left){
                st.push(temp->left);
            }
            if(!st.empty()){
                temp->right = st.top();
            }
            temp->left = NULL;
         }
        
    }
};























