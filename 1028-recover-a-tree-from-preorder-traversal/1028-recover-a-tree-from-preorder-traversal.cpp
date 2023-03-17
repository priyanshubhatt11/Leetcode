class Solution {
public:
    TreeNode* recoverFromPreorder(string s) {
        unordered_map<int, TreeNode*> mp;
        
        int j=0;
        int v =0;
        while(j<s.size() && s[j] >='0' && s[j] <='9'){
            v = v*10 + (s[j] -'0');
            j++;
        }
        
        mp[0] = new TreeNode(v);
        
        int n = s.size();
        for(int i=j;i<s.size();){
            bool f1=false, f2=false;
            int c =0;
            string num = "";
            while(i<s.size() && s[i] == '-'){
                c++;
                f1=true;
                i++;
            }
            
            while(i<s.size() && s[i] >='0' && s[i]<='9'){
                num.push_back(s[i]);
                i++;
                f2=true;
            }
            
            int x = stoi(num);
            mp[c] = new TreeNode(x);
            //cout<<c<<" "<<x<<endl;
            if(mp[c-1]->left == NULL){
                mp[c-1]->left = mp[c];
            }
            else mp[c-1]->right = mp[c];
            
        }
        return mp[0];
    }
};




