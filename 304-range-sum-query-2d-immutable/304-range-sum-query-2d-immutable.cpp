class NumMatrix {
public:
    vector<vector<int>> sum;
    NumMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m= mat[0].size();
        sum = vector<vector<int>> (n+1 , vector<int> (m+1, 0));
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                sum[i][j] = sum[i-1][j] + sum[i][j-1] + mat[i-1][j-1] - sum[i-1][j-1];  // we sub sum[i-1][j-1] because it is added two times in prefix sum
            }
        }
        for(auto i:sum){
            for(int j:i)cout<<j<<" ";
            cout<<endl;
        }
   
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row2++;
        col2++;
        return sum[row2][col2] - sum[row1][col2] - sum[row2][col1] + sum[row1][col1];  // we add sum[row1][col1] because it is subtracted two times
    }
};
