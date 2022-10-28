class Solution {
public:
    bool checkDistances(string s, vector<int>& dis) {
        unordered_map<int,int> map;
        for(int i=0;i<s.size();i++){
            if(map.find(s[i]) == map.end()){
                map[s[i]] = i+1;
            }
            else{
                if( i - map[s[i]] != dis[s[i] - 'a'])return false;
            }
        }
        return true;
    }
};