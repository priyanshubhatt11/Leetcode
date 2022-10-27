class Solution {
public:
    
    int solve(vector<vector<int>>&img1, vector<vector<int>> &img2, int r, int c){
        int count =0;
        int n = img1.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(r+i < 0 || r+i >=n || c+j <0 || c +j >=n)continue;
                
                if(img1[i][j] + img2[i+r][j+c] == 2)count++;
            }
        }
        return count;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int ans =0;
        int n = img1.size();
        for(int i= -n+1 ;i<n;i++){
            for(int j = -n+1; j<n; j++){
                ans = max(ans, solve(img1, img2, i, j));
                //cout<<i<<j<<" ";
            }
            //cout<<endl;
        }
        return ans;
    }
};