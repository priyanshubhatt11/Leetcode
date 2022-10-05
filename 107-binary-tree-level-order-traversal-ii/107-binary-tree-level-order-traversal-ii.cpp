class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == NULL)return {};
        vector<vector<int>> ans;
        vector<int>vec;
        
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty()){
            TreeNode *temp = q.front();
            q.pop();
            if(temp == NULL){
                ans.push_back(vec);
                vec.clear();
                //cout<<endl;
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                vec.push_back(temp->val);
                cout<<temp->val<<" ";
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};