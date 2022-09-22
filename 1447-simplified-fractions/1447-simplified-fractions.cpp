class Solution {
public:
    
    int findgcd(int n,int m){
        while(n!=m){
            if(n>m) n=n-m;
            else m=m-n;
        }
        return n;
    }
    
    vector<string> simplifiedFractions(int n) {
        vector<string> ans;
        for(int i=1;i<n;i++){
            for(int j= i+1;j<=n;j++){
                
               if(findgcd(i,j) == 1){
                
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