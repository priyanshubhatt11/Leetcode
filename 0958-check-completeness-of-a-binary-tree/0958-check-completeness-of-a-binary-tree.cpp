
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        
        
        queue<TreeNode*> q;
        q.push(root);
        bool flag = false;
        while(!q.empty()){
            int k = q.size();
            
            while(k--){
                TreeNode* temp = q.front();
                q.pop();
                
               
                
                if(!flag && (temp->left == NULL || temp->right == NULL))flag = true;
                else if(flag && (temp->left != NULL || temp->right != NULL))return false;
                if(temp->left == NULL && temp->right != NULL)return false;
                    
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
            
        }
   
        
        return true;
    }
};