class Solution {
public:
    int countLatticePoints(vector<vector<int>>& cir) {
        //vector<vector<bool>> vis(201, vector<bool> (201, false));
        int ans=0;
        for(int i=0;i<=200;i++){
            for(int j=0;j<=200;j++){
                for(int k =0;k<cir.size();k++){
                    int x =  (cir[k][0] - i) * (cir[k][0] - i) + (cir[k][1] - j)*(cir[k][1] - j);
                    if(x <= cir[k][2] * cir[k][2]){
                        ans++;
                        break;
                    }
                }
            }
        }
        return ans;
        
    }
};