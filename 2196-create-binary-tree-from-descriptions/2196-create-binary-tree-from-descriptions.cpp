class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& desc) {
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> st1,st2;
        
        for(auto i:desc){
            if(!mp.count(i[0])){
                mp[i[0]] = new TreeNode(i[0]);
            }
            if(!mp.count(i[1])){
                mp[i[1]] = new TreeNode(i[1]);
            }
            if(i[2] == 1) mp[i[0]]->left = mp[i[1]];
            else mp[i[0]]->right = mp[i[1]];
            st1.insert(i[0]);
            st2.insert(i[1]);
        }
        int x;
        for(auto i:st1){
            if(!st2.count(i)){
                x =i;
                break;
            }
        }
        return mp[x];
        
    }
};