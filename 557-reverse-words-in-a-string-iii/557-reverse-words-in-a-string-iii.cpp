class Solution {
public:
    string reverseWords(string s) {
        int j=0, x=0;
        string ans = "";
        for(int i=0;i<s.size();i++){
            if(s[i] == ' '){
                // cout<<i<<" "<<j<<" "<<x<<" - ";
                string nn = s.substr(j, x);
                reverse(nn.begin(), nn.end());
                //cout<<nn<<" ";
                ans += nn;
                x=0;
                j=i+1;  
            }
            x++;
        }
        if(ans.size() > 0)ans+= " ";
        string nn = s.substr(j,x);
        //cout<<j<<" "<<x<<" - ";
        reverse(nn.begin(), nn.end());
        ans += nn;
        return ans;
    }
};