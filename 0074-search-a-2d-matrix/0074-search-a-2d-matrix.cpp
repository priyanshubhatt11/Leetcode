class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size();
        int m = mat[0].size();
        for(int i=0;i<n;i++){
            if(binary_search(mat[i].begin(), mat[i].end() , target))return true;
        }
        return false;
    }
};