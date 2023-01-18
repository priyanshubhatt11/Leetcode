class Solution {
public:
    void rotate(vector<vector<int>>& mat){
        for(int i=0;i<mat.size();i++){
            for(int j=i;j<mat.size();j++){
                int temp = mat[i][j];
                mat[i][j] = mat[j][i];
                mat[j][i] = temp;
            }
        }
        for(auto &i:mat)reverse(i.begin(),i.end());
    }
};