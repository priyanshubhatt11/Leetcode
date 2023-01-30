class Solution {
public:
    
    int solve(char ch, string s, int k){
        int ans =0;
        int c =0;
        int j=0;
        for(int i=0;i<s.size();i++){
            if(s[i] != ch)c++;
            while(c>k){
                if(s[j] != ch)c--;
                j++;
            }
            ans = max(ans, i-j+1);
        }
        return ans;
    }
    
    int characterReplacement(string s, int k) {
        int ans =0;
        for(char i='A';i<='Z';i++){
            ans = max(ans, solve(i, s, k));
        }
        return ans;
    }
};