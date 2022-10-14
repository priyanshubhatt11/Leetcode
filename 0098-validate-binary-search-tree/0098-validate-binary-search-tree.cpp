class Solution {
public:
    
    void inorder(TreeNode *root, vector<int> &vec){
        if(root == NULL)return;
        inorder(root->left, vec);
        vec.push_back(root->val);
        inorder(root->right, vec);
    }
    
    bool isValidBST(TreeNode* root) {
        vector<int> vec;
        inorder(root, vec);     // inorder of BST is sorted array
        for(int i=0;i<vec.size()-1;i++){
            if(vec[i] >= vec[i+1])return false;
        }
        return true;
    }
};