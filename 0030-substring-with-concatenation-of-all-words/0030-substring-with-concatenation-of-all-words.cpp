class Solution {
public:
    
    bool isvalid(string s, unordered_map<string, int> map, int sz){
        for(int i=0;i<s.size();i += sz){
            string ss = s.substr(i, sz);
            map[ss]--;
            if(map[ss] < 0)return false;
        }
        return true;
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> map;
        for(string i :words){
            map[i]++;
        }
        
        int n = s.size(), mx = words.size(), sz = words[0].size();
        int m = mx * sz;
        
        vector<int> ans;
        for(int i=0; i+m <=n ;i++){
            //cout<<s.substr(i,m)<<endl;
            if(isvalid(s.substr(i, m) , map, sz)){
                ans.push_back(i);
                
            }
        }
        return ans;
    }
};