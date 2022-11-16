class Solution {
public:
    string mostCommonWord(string s, vector<string>& banned) {
        for(char &i: s){
            if( !isalpha(i)) i = ' ';
        }
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        
        unordered_set<string> set(banned.begin(), banned.end());
        
        unordered_map<string , int> map;
        
        stringstream ss(s);
        string p;
        while(ss >> p){
            if(set.find(p) == set.end()){
                map[p]++;
            }
        }
        string ans = "";
        int c=0;
        for(auto i:map){
            if(c < i.second){
                ans = i.first;
                c = i.second;
            }
        }
        return ans;
        
       
    }
};