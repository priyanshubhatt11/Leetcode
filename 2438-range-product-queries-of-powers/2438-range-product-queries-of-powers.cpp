class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& que) {
        long long mod = 1000000007;
        vector<int> vec;
        for(int i=0;i<32;i++){
            if((n & (1<<i)) != 0){
                vec.push_back(1<<i);
            }
        }
        int nn = vec.size();
//        vector<long long> pref(nn, 1);
//         pref[0] = vec[0];
        
//         for(int i=1;i<nn;i++){
//             pref[i] = (pref[i-1] * vec[i]);
//             pref[i] %= mod;
//         }
        
        vector<int> ans;
        // for(auto i: que){
        //     int x;
        //     if(i[0]>=1){
        //         x = pref[i[1]] / pref[i[0]-1];
        //     }
        //     else{
        //         x = pref[i[1]];
        //     }
        //     ans.push_back(x);
        // }
        long long pro =1;
        for(auto i:que){
            pro = 1;
            for(int j=i[0];j<=i[1];j++){
                pro *= vec[j];
                pro %= mod;
            }
            ans.push_back(pro);
        }
        return ans;
    }
};










