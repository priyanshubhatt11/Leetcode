class Solution {
public:
    int countGoodSubstrings(string s) {
        if(s.size()<3)return 0;
        char a = s[0], b= s[1], c= s[2];
        int ans=0;
        for(int i=1;i<=s.size()-2;i++){
            //cout<<a<<" "<<b<<" "<<c<<" - ";
            if(a!=b && b!=c && c!=a)ans++;
            a = s[i];
            b = s[i+1];
            c = s[i+2];
        }
        return ans;
    }
};