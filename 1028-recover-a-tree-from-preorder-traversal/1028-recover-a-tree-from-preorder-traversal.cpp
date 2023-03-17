class Solution {
public:
    TreeNode* recoverFromPreorder(string s) {
        unordered_map<int, TreeNode*> mp;
        
         int j=0;
        // int v =0;
        // while(j<s.size() && s[j] >='0' && s[j] <='9'){
        //     v = v*10 + (s[j] -'0');
        //     j++;
        // }
        
        //mp[0] = new TreeNode(v);
        
        int n = s.size();
        for(int i=j;i<s.size();){
            int c =0, num = 0;
            while(i<s.size() && s[i] == '-'){
                c++;
                i++;
            }
            
            while(i<s.size() && s[i] >='0' && s[i]<='9'){
                num = num*10 + (s[i] - '0');
                i++;
            }
            
            mp[c] = new TreeNode(num);
            //cout<<c<<" "<<x<<endl;
            if(c>0){    // their is no c-1 node of root node
                if(mp[c-1]->left == NULL){
                    mp[c-1]->left = mp[c];
                }
                else mp[c-1]->right = mp[c];
            }
            
            
        }
        return mp[0];
    }
};




