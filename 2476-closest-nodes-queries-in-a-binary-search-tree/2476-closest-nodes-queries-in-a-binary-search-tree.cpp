
class Solution {
public:
    
    void inorder(TreeNode* root, vector<int> &vec){
        if(root == NULL)return;
        inorder(root->left, vec);
        vec.push_back(root->val);
        inorder(root->right, vec);
    }
    
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& q) {
        vector<int> vec;
        inorder(root, vec);
        vector<vector<int>> ans;
        
        //1 2 4 6 9 13 14 15
        for(auto i:q){
            vector<int> vv;
            int idx1 = upper_bound(vec.begin(), vec.end(), i) - vec.begin();
            idx1--;
            if(idx1 < 0){
                vv.push_back(-1);
            }
            else vv.push_back(vec[idx1]);
            
            int idx2 = lower_bound(vec.begin(), vec.end(), i) - vec.begin();
            if(idx2 >= vec.size()){
                vv.push_back(-1);
            }
            else vv.push_back(vec[idx2]);
            
            ans.push_back(vv);
            
        }
        
        return ans;
    }
};