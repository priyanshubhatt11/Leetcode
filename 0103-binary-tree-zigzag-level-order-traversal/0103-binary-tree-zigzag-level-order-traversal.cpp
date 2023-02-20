
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL)return {};
        queue<TreeNode*> q;
        vector<vector<int>> vec;
        bool flag = true;
        q.push(root);
        while(!q.empty()){
            vector<int> temp;
            int k = q.size();
            while(k--){
                TreeNode* head = q.front();
                q.pop();
                temp.push_back(head->val);
                if(head->left)q.push(head->left);
                if(head->right)q.push(head->right);
            }
            if(!flag)reverse(temp.begin(), temp.end());
            flag = !flag;
            vec.push_back(temp);
        }
        return vec;
    }
};