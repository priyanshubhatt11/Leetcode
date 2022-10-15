class Solution {
public:
    const static int N = 127;
	int dp[N][N];

	string str;
	int n;
	inline int xs(int x) { return x == 1 ? 0 : x < 10 ? 1 : x < 100 ? 2 : 3; }

	int solve(int left, int k) {
		if(k < 0) return N;
		if(left >= n or n - left <= k) return 0; 

		int& ans = dp[left][k];
		if(ans != -1) return ans;
		ans = N;

		int cnt[26] = {0};
		// we try to make s[left:j] (both inculded) as one group,and all chars in this group should bthe same.
		// so we must keep the most chars in this range and remove others and the number of chars we need to remove is (j - left + 1 - most)
		for(int j = left, most = 0; j < n; j++) {
			most = max(most, ++cnt[str[j] - 'a']);  
			ans = min(ans, 1 + xs(most) + solve(j + 1, k - (j - left + 1 - most)));
		}
		return ans;
    }
	int getLengthOfOptimalCompression(string s, int k) {
		memset(dp, -1, sizeof(dp));
		str = s;
		n = s.size();
		return solve(0, k);
	}
};