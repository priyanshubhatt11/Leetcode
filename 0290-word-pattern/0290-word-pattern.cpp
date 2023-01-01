class Solution {
public:
    bool wordPattern(string pat, string s) {
        unordered_map<char, string> mp1;
        unordered_map<string , char> mp2;
        stringstream ss(s);
        string p = "";
        int i=0;
        while( ss >> p){
            if(mp1[pat[i]] != "" && mp1[pat[i]] != p)return false;
            mp1[pat[i]] = p;
            if(mp2.find(p) != mp2.end() && mp2[p] != pat[i])return false;
            mp2[p] = pat[i];
            i++;
        }
        if(i!=pat.size())return false;
        return true;
    }
};