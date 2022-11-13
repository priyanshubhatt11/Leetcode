
class Solution {
public:
    
    int solve(vector<int> &nums){
        vector<pair<int,int>> vec;
        
        for(int i=0;i<nums.size();i++){
            vec.push_back({nums[i], i});
        }
        
        sort(vec.begin(), vec.end());
        int c =0;
        for(int i=0;i<vec.size();i++){
            if(vec[i].second != i){
                swap(vec[i], vec[vec[i].second]);
                c++;
                i--;    // doest not match === check again
            }
        }
        return c;
    
    }
    
    int minimumOperations(TreeNode* root) {
        int ans= 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int k = q.size();
            vector<int> vec;
    
            while(k--){
                TreeNode* node = q.front();
                q.pop();
                vec.push_back(node->val);
                
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            
            ans += solve(vec);
        }
        return ans;
    }
};