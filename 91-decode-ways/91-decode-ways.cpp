class Solution {
public:
int calc(vector<int>&dp,string s,int ind){
    if(ind>=s.size()){
        return 1;
    }
    if(dp[ind]!=-1){
        return dp[ind];
    }
    
    int ans=0;
    int temp = 0;
    temp = s[ind] - '0';

    int temp2 = 0;
    if(ind+1 < s.size())temp2 = (temp*10) + (s[ind+1]-'0');
    
    if(temp >=1 and temp<=26){
        ans += calc(dp,s,ind+1);
    }
    if(temp>0 and temp2>=10 and temp2<=26){
        ans += calc(dp,s,ind+2);
    }
    
    return dp[ind] = ans;
}

int numDecodings(string s) {
    vector<int>dp(s.size()+1,-1);
    
    return calc(dp,s,0);
}
};