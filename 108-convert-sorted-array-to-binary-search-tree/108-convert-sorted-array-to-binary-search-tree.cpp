
class Solution {
public:
    
    TreeNode *solve(vector<int> &nums, int i, int j){
        if(i<=j){
            int mid = (i+j)/2;
            TreeNode * node = new TreeNode(nums[mid]);
            node->left = solve(nums, i, mid-1);
            node->right = solve(nums, mid+1, j);
            return node;
        }
        return NULL;    
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(nums, 0, nums.size()-1);
    }
};