class Solution {
public:
    
    void inorder(TreeNode *root, vector<int>&vec){
        if(root == NULL)return;
        inorder(root->left, vec);
        vec.push_back(root->val);
        inorder(root->right, vec);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> vec;
        inorder(root1, vec);
        inorder(root2, vec);
        sort(vec.begin(), vec.end());
        return vec;
    }
};