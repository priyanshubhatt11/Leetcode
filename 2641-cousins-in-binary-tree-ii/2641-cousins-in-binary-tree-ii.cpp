class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        root->val=0;
        queue<pair<TreeNode*,TreeNode*>>qp;
        queue<pair<TreeNode*,TreeNode*>>temp;
        qp.push({root,root});
        temp.push({root,root});
        unordered_map<TreeNode*,int>mp;
        while(qp.size()>0)
        {
             int sum=0;
             int len=qp.size();
             
             for(int i=0;i<len;i++)
             {    
            TreeNode*child=qp.front().first;
            TreeNode*parent=qp.front().second;
             sum+=child->val;
            qp.pop();
            
            mp[parent]+=child->val;
            if(child->left!=NULL)
            {
                qp.push({child->left,child});
                temp.push({child->left,child});
            }
            if(child->right!=NULL)
            {
                qp.push({child->right,child});
                  temp.push({child->right,child});
            }
             }
             for(int i=0;i<len;i++)
             {
                 TreeNode*child=temp.front().first;
                 TreeNode*parent=temp.front().second;
                  temp.pop();
                  child->val=sum-mp[parent];
             }
        }
        return root;
    }
};