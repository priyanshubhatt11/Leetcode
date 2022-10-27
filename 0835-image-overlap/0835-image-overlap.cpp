class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size();
        int ans =0;
        for(int dx = -n-1; dx < n; dx++){
            for(int dy = -n-1;dy < n; dy++){
                int temp =0;
                for(int x =0; x<n && x + dx < n ;x++){
                    if(x + dx < 0)continue;
                    for(int y =0; y< n && y + dy < n; y++){
                        if(y + dy < 0)continue;
                        if(A[x][y] + B[x+dx][y+dy] == 2)temp++;
                    }
                }
                ans = max(ans, temp);
            }
        }
        return ans;
    }
};