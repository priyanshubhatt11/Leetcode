class Solution {
public:
    bool binaryS(vector<int>&vec, int tar){
        int l=0,h=vec.size()-1;
        while(l<=h){
            int mid = (l+h)/2;
            if(vec[mid] == tar)return true;
            else if(vec[mid] > tar)h = mid-1;
            else l = mid+1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& mat, int tar) {
        int n = mat.size();
        int m = mat[0].size();
        for(int i=0;i<n;i++){
            if(binaryS(mat[i], tar))return true;
        }
        return false;
    }
};




















