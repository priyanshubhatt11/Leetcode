
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        if(root == NULL)return NULL;
        vector<int> vec;
        stack<TreeNode*> s;
        TreeNode* curr=root;
        while( curr!=NULL || s.empty()==false )
        {
            while( curr!=NULL ){
                s.push(curr);
                curr=curr->left;
            }
            curr=s.top();
            if(curr!=NULL)
                vec.push_back(curr->val);
            s.pop();
            curr=curr->right;
      }
      
        TreeNode* temp = new TreeNode(vec[0]);
        TreeNode* pp = temp;
        for(int i=1;i<vec.size();i++){
            pp->left = NULL;
            pp->right = new TreeNode(vec[i]);
            pp = pp->right;
        }
      
      return temp;
    }
};