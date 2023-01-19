class Solution {
public:
    int numberOfWays(string s) {
        int c=0;
        for(auto i:s)if(i == 'S')c++;
        
        if(c == 0 || c%2 ==1)return 0;
        
        long long ans=1;
        c=0;
        for(int i=0;i<s.size();i++){
            if(s[i] == 'S')c++;
            if(c==2){
                i++;
                long long cnt=1;
                while(i<s.size() && s[i] == 'P'){
                    cnt++;
                    i++;
                }
                if(i == s.size())break; // reference example 2
                ans = (ans*cnt);
                ans %=1000000007;
                c=0;
                i--;
            }
        }
        return ans;
    }
};








