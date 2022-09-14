
class Solution {
public:
    int count=0;
    void solve(TreeNode *root, vector<int> mp){
        if(root == NULL)return ;
        
        mp[root->val]++;
        
        if(root->left == NULL && root->right == NULL){
            int oddC = 0;
            for(auto i:mp){
                if(i%2 != 0){
                    oddC++;
                }
            }
            if(oddC <= 1){
                count++;
            }
            return;
        }
        solve(root->left, mp);
        solve(root->right, mp);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> mp(10, 0);
        solve(root, mp);
        return count;
        
    }
};