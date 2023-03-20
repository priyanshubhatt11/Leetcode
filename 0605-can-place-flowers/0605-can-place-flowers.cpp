class Solution {
public:
    bool canPlaceFlowers(vector<int>& numms, int n) {
        vector<int> nums;
        nums.push_back(0);
        for(auto i:numms){
            nums.push_back(i);
        }
        nums.push_back(0);
        for(int i=1;i<nums.size()-1;i++){
            if(nums[i-1] + nums[i] + nums[i+1] == 0){
                n--;
                i++;
            }
        }
        
        if(n<=0)return true;
        return false;
        
    }
};