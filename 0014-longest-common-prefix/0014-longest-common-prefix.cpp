class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string ans = "";
        for(int i=0;i<strs[0].size();i++){
            int c =0;
            
            
            for(int j=0;j<strs.size();j++){
                if(strs[0][i] == strs[j][i]){
                    c++;
                }
            }
           // cout<<c<<" ";
            if(c == strs.size())ans.push_back(strs[0][i]);
            else return ans;
        }
        return ans;
    }
};