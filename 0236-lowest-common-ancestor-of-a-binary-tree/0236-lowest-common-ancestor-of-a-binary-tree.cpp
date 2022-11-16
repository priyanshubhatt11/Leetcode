

class Solution {
public:
//     bool flag = false;
//     void solve(TreeNode* root, TreeNode* p,  vector<TreeNode*> &vec){
//         if(root == NULL)return;
        
//         if(root->val == p->val){
//             flag = true;
//             vec.push_back(root);
//             return;
//         }
//         vec.push_back(root);
//         solve(root->left, p, vec);
//         solve(root->right, p, vec);
        
//         if(!flag) vec.pop_back();
//     }
    
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         vector<TreeNode*> vec1, vec2;
//         solve(root, p, vec1);
//         flag = false;
//         solve(root, q, vec2);
        
//         TreeNode*temp;
//         for(int i=0;i<vec1.size() && i<vec2.size();i++){
//             if(vec1[i]->val != vec2[i]->val)break;
//             temp = vec1[i];
//         }
//         return temp;
//         //for(auto i:vec1)cout<<i->val<<" ";
//         //return root;
//     }
    
    //      OR
    
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)return NULL;
        
        if(root == p || root == q)return root;
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        if(left == NULL)return right;   // returning not null value
        
        if(right == NULL)return left;
        
        return root;
        
    }
};




















