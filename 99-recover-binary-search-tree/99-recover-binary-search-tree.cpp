class Solution {
public:
    
    
    TreeNode *prev = NULL, *first = NULL, *second = NULL;
    
//     int i=0;
//     void inorder(TreeNode *root, vector<int>&vec){
//         if(root == NULL)return;
        
//         inorder(root->left, vec);
//         vec.push_back(root->val);
//         inorder(root->right, vec);
//     }
    
//     void inorderInsert(TreeNode *root, vector<int>&vec){
//         if(root == NULL)return;
//         inorderInsert(root->left, vec);
//         if(vec[i] != root->val){
//             root->val = vec[i];
//         }
//         i++;
//         inorderInsert(root->right, vec);
        
       
//     }
    
    void inorder2(TreeNode * root){
        if(root == NULL)return;
        
        
        inorder2(root->left);
        
        if(prev!=NULL && prev->val > root->val){
            if(first == NULL)   first = prev;
            
            second = root;
        }
        prev = root;
        
        inorder2(root->right);
        
    }
    
    void recoverTree(TreeNode* root) {
//         vector<int> vec;
//         inorder(root,vec);
//         sort(vec.begin(), vec.end());
        
//         inorderInsert(root,  vec);
        
        
        inorder2(root);
        swap(first->val, second->val);
    }
};