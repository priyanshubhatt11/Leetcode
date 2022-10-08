class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> vec;
        for(int i=0;i<nums.size();i++){
            int j=i;
            string s = "";
            s += to_string(nums[i]);
            
            while(j<nums.size()-1 && nums[j]+1 == nums[j+1]){
                j++;
            }
            if(i!=j){
                s += "->";
                s += to_string(nums[j]);
            }
            
            vec.push_back(s);
            i = j;
        }
        return vec;
    }
};