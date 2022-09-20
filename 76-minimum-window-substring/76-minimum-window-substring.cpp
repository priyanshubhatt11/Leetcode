class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int>map;
        for(int i=0;i<t.size();i++){
            map[t[i]]++;
        }
        
        int start=0, c=0,j=0, mm = INT_MAX;
        for(int i=0;i<s.size();i++){
            
            if(map[s[i]] > 0)c++;
            
            map[s[i]]--;
            
            while(c == t.length()){
                if(mm > i-j+1){
                    mm = i-j+1;
                    start = j;
                }
                map[s[j]]++;
                if(map[s[j]] >0)c--;
                
                j++;
            }
        }
        if(mm == INT_MAX)return "";
        return s.substr(start, mm);
    }
};