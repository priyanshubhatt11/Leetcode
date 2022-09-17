class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        unordered_map<char,int> map;
        int ans=0;
        int j=0;
        for(int i=0;i<s.size();i++){
            
            map[s[i]]++;
            while(map.size() == 3){
                ans += n-i;
                map[s[j]]--;
                if(map[s[j]] == 0)map.erase(s[j]);
                j++;
            }
        }
        return ans;
    }
};