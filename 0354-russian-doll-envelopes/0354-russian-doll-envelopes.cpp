//https://www.youtube.com/watch?v=MYHajVcnXSA

class Solution {
public:
    
    bool static comp(vector<int> &A, vector<int> &B){
        if(A[0] != B[0])return A[0] < B[0];
        return A[1] > B[1];
    }
    
    // applying longest increasing subsequence in height;
    
    int maxEnvelopes(vector<vector<int>>& env) {
        sort(env.begin(), env.end(), comp);
        
        vector<int> vec;
        for(int i=0;i<env.size();i++){
            
            int x = env[i][1];
            
            int idx = lower_bound(vec.begin(), vec.end(), x) - vec.begin();
            
            if(idx >= vec.size()){
                vec.push_back(x);
            }
            else{
                vec[idx] = x; 
            }
        }
        return vec.size();
        
    }
};