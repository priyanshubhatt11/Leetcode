class Solution {
public:
    
    unordered_map<string , int> map;

    int isvalid(string s){
        for(int i=1;i<s.size();i++){
            string sff = s.substr(i);
             if(map.find(s.substr(0,i))!= map.end() && (map.find(sff) != map.end() || isvalid(sff))){
                 return true;
             }
        }
        return false;
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for(auto i:words){
            map[i]++;
        }
        vector<string> ans;
        
        for(auto i:words){
            if(isvalid(i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};