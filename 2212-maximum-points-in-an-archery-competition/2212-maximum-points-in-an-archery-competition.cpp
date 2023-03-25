class Solution {
public:
    
    int temp = INT_MIN;
    vector<int> ans;
    
    int solve(vector<int>&vec, int num, vector<int>&alice, int idx, int sum){
        
        if(idx <0){
            if(sum > temp){
                temp = sum;
                ans = vec;
            }
            return sum;
        }
        int t=0,nt =0;
        if(num - alice[idx]>0){  // remaining arrows - alice that index arrows > 0
            vec[idx] = alice[idx]+1;    // one extra only can offer us the point
            t = solve(vec, num-alice[idx]-1, alice, idx-1, sum + idx);
            vec[idx] =0; // backtrack
        }
        nt = solve(vec, num, alice, idx-1, sum);
        return max(t, nt);
    }
    
    vector<int> maximumBobPoints(int num, vector<int>& alice) {
        vector<int> vec(12,0);
        solve(vec, num, alice, 11, 0);
        
        int sum=0;
        for(int i:ans){ 
            sum += i;
        }
        ans[0] += num - sum;    // remaining arrows added , it can be added to any indices
        
        return ans;
    }
};