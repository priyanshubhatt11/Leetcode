class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.size() <k)return false;
        unordered_set<string> m;
        int l = s.size();
        for(int i=0;i<=l-k;++i){
            string nn = s.substr(i,k);
            m.insert(nn);
        }
        cout<<m.size();
        return m.size()==pow(2,k);
    }
};