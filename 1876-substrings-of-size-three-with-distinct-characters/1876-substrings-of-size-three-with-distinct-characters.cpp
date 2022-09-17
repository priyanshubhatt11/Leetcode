class Solution {
public:
    int countGoodSubstrings(string s) {
        unordered_map<char,int> map;
        int ans=0;
        
        for(int i=0;i<s.size();i++){
            map[s[i]]++;
            
            int j = i-3;
            if(j>=0){
                map[s[j]]--;
                if(map[s[j]] == 0){
                    //cout<<s[j]<<" ";
                    map.erase(s[j]);
                }
            }
            if(map.size() == 3)ans++;
        }
        return ans;
        
    }
};