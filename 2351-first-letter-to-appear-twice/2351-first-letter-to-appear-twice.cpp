class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_map<int,int> map;
        char c ;
        for(int i=0;i<s.size();i++){
            map[s[i]]++;
            if(map[s[i]] == 2){
                c = s[i];
                return c;
            }
        }
        return c;
    }
};