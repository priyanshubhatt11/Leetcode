class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        unordered_map<char, int> mp;
        int n = chars.size();
        for(int i=0;i<n;i++){
            mp[chars[i]] = vals[i];
        }
        
        int ans =0, c =0;
        for(int i=0;i<s.size();i++){
            if(mp.count(s[i])){
                c += mp[s[i]];
            }
            else{
                c += (s[i] -'a')+1;
            }
            ans = max(ans, c);
            if(c <0)c=0;
        }
        return ans;
        
    }
};