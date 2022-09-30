class Solution {
public:
    
    bool isvalid(string s, unordered_map<string ,int> map, int x){
        for(int i=0;i<s.size();i += x){
            string ss = s.substr(i, x);
            if(map.find(ss) != map.end()){
                if(--map[ss] == -1)return false;
            }
            else{
                return false;
            }
        }
        return true;
        
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        unordered_map<string ,int> map;
        for(string ss : words){
            map[ss]++;
        }
        int n = s.size(), m = words.size();
        int sx = m * words[0].size();
        // cout<<sx;
        for(int i=0;i+sx<=n;i++){
            
            if(isvalid(s.substr(i, sx), map, words[0].size())){
                ans.push_back(i);
                //i+= m-1;
            }
        }
        
        
        
        return ans;
    }
};