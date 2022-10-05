
class Solution {
public:
    
    void inorder(TreeNode *root, vector<int> &vec){
        if(root==NULL)return;
        inorder(root->left, vec);
        vec.push_back(root->val);
        inorder(root->right, vec);
    }
    
    bool findTarget(TreeNode* root, int k) {
        vector<int> vec;
        inorder(root, vec);  // sorted vector
        int i=0, j=vec.size()-1;
        
        while(i<j){
            int sum = vec[i] + vec[j];
            if(sum == k)return true;
            if(sum > k)j--;
            else i++;
        }
        return false;
        
    }
};