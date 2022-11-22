class Solution {
public:

    // declare a dp

    int dp[105][10005];

    int helper(vector<int>& arr, int i, int n, int sum)
    {
        // base case

        if(sum == 0)
        {
            return 0;
        }

        if(i >= n || sum < 0)
        {
            return INT_MAX - 1000;
        }

        // if already calculated

        if(dp[i][sum] != -1)
        {
            return dp[i][sum];
        }

        // at each ith element we have two options either include or exclude

        int mini = INT_MAX;

        // inclusion part

        if(arr[i] <= sum)
        {
            mini = min(mini, 1 + helper(arr, i, n, sum - arr[i]));
        }

        // exclusion part

        mini = min(mini, helper(arr, i + 1, n, sum));

        // store the res in dp

        return dp[i][sum] = mini;
    }

    int numSquares(int n) {

        vector<int> arr;

        // find all the squares between 1 to n

        for(int i = 1; i * i <= n; i++)
        {
            arr.push_back(i * i);
        }

        // initialize dp with -1

        memset(dp, -1, sizeof(dp));

        return helper(arr, 0, arr.size(), n);
    }
};
