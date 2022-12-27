class Solution {
public:
    int closetTarget(vector<string>& str, string tar, int start) {
        int n = str.size();
        int ans =INT_MAX;
        int x;
        for(int i=0;i<n;i++){
            if(str[i] == tar){
                if(i<=start)    x = min(start - i , i + n - start);
                else x = min(i - start , start + n-i);
                ans = min(ans , x);
            }
        }
        if(ans == INT_MAX)return -1;
        return ans;
    }
};