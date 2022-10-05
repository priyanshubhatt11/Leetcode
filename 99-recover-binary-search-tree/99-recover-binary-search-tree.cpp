class Solution {
public:
    int i=0;
    void inorder(TreeNode *root, vector<int>&vec){
        if(root == NULL)return;
        
        inorder(root->left, vec);
        vec.push_back(root->val);
        inorder(root->right, vec);
    }
    
    void inorderInsert(TreeNode *root, vector<int>&vec){
        if(root == NULL)return;
        inorderInsert(root->left, vec);
        if(vec[i] != root->val){
            root->val = vec[i];
        }
        i++;
        inorderInsert(root->right, vec);
        
       
    }
    void recoverTree(TreeNode* root) {
        vector<int> vec;
        inorder(root,vec);
        sort(vec.begin(), vec.end());
        
        inorderInsert(root,  vec);
    }
};