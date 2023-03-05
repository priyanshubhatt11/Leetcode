class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL)return {};
        vector<vector<int>> ans;
        vector<int> vec;
        
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode *temp = q.front();
            q.pop();
            if(temp == NULL){
                ans.push_back(vec);
                vec.clear();
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                vec.push_back(temp->val);
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
        }
        return ans;
    }
};