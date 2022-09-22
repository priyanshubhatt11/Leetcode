class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> ans;
        for(int i=1;i<n;i++){
            for(int j= i+1;j<=n;j++){
                
               if(gcd(i,j) == 1){
                
                    string nn = "";
                    nn = to_string(i) + "/" + to_string(j);

                    //cout<<nn<<" ";
                    ans.push_back(nn);
               }
            }
        }
        return ans;
    }
};