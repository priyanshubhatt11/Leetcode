class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> vec(n+1, 0);
        for(int i=0;i<n;i++){
            vec[nums[i]]++;     // frequency
        }
        int fir, sec;
        
        for(int i=1;i<=n;i++){
            if(vec[i] == 2){
                fir = i;
            }
            if(vec[i] == 0){
                sec = i;
            }
        }
        return {fir, sec};
    }
};