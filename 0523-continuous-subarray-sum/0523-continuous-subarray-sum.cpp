class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        int sum =0;
        map[0] = -1;    // we take map[0] as -1 test this case -> [2,4,3] k=6

        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            cout<<sum<<" ";
            if(k!= 0)sum = sum % k;

            if(map.count(sum)){
                if(i - map[sum] > 1)    // acc to question length >= 2;
                    return true;
            }
            else{
                map[sum] = i;
            }
            
        }
        return false;
    }
};