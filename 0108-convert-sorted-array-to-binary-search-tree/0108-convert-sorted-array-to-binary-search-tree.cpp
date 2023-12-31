
class Solution {
public:
    
    TreeNode* solve(vector<int>&nums, int i, int j){
        if(i<=j){
            
            int mid = (i+j)/2;
            TreeNode* temp = new TreeNode(nums[mid]);
            temp->left = solve(nums, i, mid-1);
            temp->right = solve(nums, mid+1, j);
            return temp;
        }
        return NULL;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return solve(nums, 0, n-1);
    }
};