class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int n = words[0].size();
        vector<vector<int>> h (n, vector<int> (26,0));
        for (auto& word:words) {
            for (int j = 0; j < n; j++) {
                h[j][word[j]-'a']++;
            }
        }
        vector<int> prev (n+1, 1);
        vector<int> cur (n+1, 0);
        int m = target.length();
        for (int i = 1; i <= m; i++) {
            cur[i-1] = 0;
            for (int j = i; j <= n - m + i; j++) {
                cur[j] = (cur[j-1] + (long)prev[j-1] * h[j-1][target[i-1]-'a'])%dev;
            }
            swap(cur, prev);
        }
        return prev[n];
    }
private:
    int dev = 1000000007;
};