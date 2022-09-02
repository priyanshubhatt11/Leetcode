class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);
        //cout<<q.size();
        vector<double> ans;
        double sum;
        while(!q.empty()){
            int n = q.size();
            sum =0;
            for(int i=0;i<n;i++){
                TreeNode *node;
                node = q.front();
                q.pop();
                sum += node->val;
                
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            
            double avg = sum/n;
            
            ans.push_back(avg);
            
        }
        
        return ans;
    }
};