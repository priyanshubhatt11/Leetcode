class Solution {
public:
    int longestBeautifulSubstring(string s) {
        int c=1,ans=0, len=1;
        for(int i=0;i<s.size()-1;i++){
            if(s[i] == s[i+1]){
                len++;
            }
            else if(s[i] < s[i+1]){
                c++;
                len++;
            }
            else{
                c =1;
                len =1;
            }
            if(c==5){
                ans = max(ans, len);
            }
              
        }
        return ans;
    }
};