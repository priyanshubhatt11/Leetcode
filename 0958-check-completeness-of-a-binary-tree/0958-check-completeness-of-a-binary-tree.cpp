
class Solution {
public:
    
    int height(TreeNode*root){
        if(root == NULL)return 0;
        return max(1+height(root->left), 1+ height(root->right));
    }
    bool isCompleteTree(TreeNode* root) {
        int h = height(root);
        
        queue<TreeNode*> q;
        q.push(root);
        int c =0;
        while(!q.empty()){
            int k = q.size();
            if(pow(2, c) != k)return false;
            if(c==h-2)break;
           
            c++;
            while(k--){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
            
        }
        int k = q.size();
        
        bool flag = false, ff = false, fd= false;
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            
            if(!flag && temp->right == NULL)flag = true;
            else if(temp->right != NULL && temp->left == NULL)return false;
            else if(flag && (temp->left != NULL || temp->right != NULL))return false;
            
        }
        
        return true;
    }
};