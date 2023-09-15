class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char ,int> mp;
        int ans =0;
        int j=0;
        for(int i=0;i<s.size();i++){
            if(mp.count(s[i]) ==  false){
                //cout<<mp[s[i]]<<" ";
                mp[s[i]]++;
                ans = max(ans, i-j+1);
            }
            else{
                //cout<<"f";
                mp[s[i]]++;
                while(j<s.size() && mp[s[i]] != 1){
                    mp[s[j]]--;
                    if(mp[s[j]] == 0)mp.erase(s[j]);
                    j++;
                }
            }
        }
        return ans;
    }
};