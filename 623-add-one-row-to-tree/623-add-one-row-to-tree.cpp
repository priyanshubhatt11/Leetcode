
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode *ll = new TreeNode(val);
            ll->left = root;
            return ll;
        }
        
        depth -= 2;
        queue<TreeNode*> q;
        q.push(root);
        
        while(depth > 0){
            int size = q.size();
            while(size--){
                TreeNode *cur = q.front();
                q.pop();
                if(cur->left)q.push(cur->left);
                if(cur->right)q.push(cur->right);
            }
            depth--;
        }
        
        while(!q.empty()){
            TreeNode * cur = q.front();
            //cout<<cur->val<<endl;
            q.pop();

            TreeNode*ll = new TreeNode(val);
            TreeNode *rr = new TreeNode(val);
            TreeNode *prevL = cur->left;
            TreeNode *prevR = cur->right;
            cur->left = ll;
            cur->right = rr;
            ll->left = prevL;
            rr->right = prevR;
        }
        
        
        return root;
    }
};