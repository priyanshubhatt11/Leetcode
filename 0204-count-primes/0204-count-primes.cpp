// Seive of eratosthenese

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> vec(n, false);
        int c =0;
        
        for(int i=2;i<n;i++){
            if(vec[i] == false){
                c++;
                for(int j=i;j<n;j+=i){
                    //cout<<j<<" ";
                    vec[j] = true;
                }
            }            
        }
        return c;
    }
};