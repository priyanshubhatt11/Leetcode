class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char ,int> mp;
        int ans =0;
        int j=0,i=0;
        while(i<s.size()){
            mp[s[i]]++;
            while(j<s.size() && mp[s[i]]>1){
                mp[s[j]]--;
                j++;
            }
            ans = max(ans, i-j+1);
            i++;
        }
        return ans;
    }
};