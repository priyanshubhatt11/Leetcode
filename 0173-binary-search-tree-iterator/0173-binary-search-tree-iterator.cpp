class BSTIterator {
public:
    vector<int> vec;
    int i=0;
    
    void solve(TreeNode*root, vector<int>&vec){
        if(root == NULL)return;
        solve(root->left,vec);
        vec.push_back(root->val);
        solve(root->right, vec);
    }
    
    BSTIterator(TreeNode* root) {
        solve(root, vec);
    }
    
    int next() {
        return vec[i++];
    }
    
    bool hasNext() {
        if(i<vec.size())return true;
        return false;
    }
};

