class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int j=0;
        int c=0, ans=0;
        for(int i=0;i<s.size();i++){
            c += abs(s[i] - t[i]);
            while(c > maxCost){
                c -= abs(s[j] - t[j]);
                j++;
            }
            ans = max(ans, i-j+1);
        }
        return ans;
    }
};