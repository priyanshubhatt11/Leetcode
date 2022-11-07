class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& nums) {
        set<int> set;
        for(int i=0;i<nums.size();i++){
            if(nums[i] != 0){
                for(int j=0;j<nums.size();j++){
                    for(int k=0;k<nums.size();k++){
                        if(i!=j && j!=k && i!=k){
                            int x = nums[i] * 100 + nums[j]* 10 + nums[k];
                            if(x%2 == 0){
                                set.insert(x);
                            }
                            
                        }
                    }
                }
            }
        }
        vector<int> vec;
        for(auto i:set){
            vec.push_back(i);
        }
        return vec;
    }
};