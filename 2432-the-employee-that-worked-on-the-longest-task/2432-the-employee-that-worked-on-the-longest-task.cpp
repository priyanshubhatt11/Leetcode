class Solution {
public:
    
    int hardestWorker(int n, vector<vector<int>>& vec) {
        
        int temp = vec[0][1];
        int idx =0;
        for(int i=1;i<vec.size();i++){
            if(vec[i][1] - vec[i-1][1] > temp){
                temp = vec[i][1] - vec[i-1][1];
                idx = i;
            }
            else if(vec[i][1] - vec[i-1][1] == temp){
                if(vec[i][0] < vec[idx][0]){
                    idx = i;
                }
            }
        }
        return vec[idx][0];
    }
};