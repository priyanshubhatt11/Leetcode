unordered_map<char, int> mp;
    bool static cmp(string &str1, string &str2){
            for(int i=0;i<str1.size() && i<str2.size();i++){
                if(mp[str1[i]] != mp[str2[i]])return mp[str1[i]] < mp[str2[i]];

            }
            return str1.size() < str2.size();
        }

class Solution {
public:
    
    bool isAlienSorted(vector<string>& words, string order) {
        
        for(int i=0;i<order.size();i++){
            mp[order[i]] = i;
        }
        vector<string> vec = words;
        sort(vec.begin(), vec.end(), cmp);
        return vec == words;
        
    }
};