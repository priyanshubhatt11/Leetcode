class Solution {
public:
    
    //  odd can only become odd and even can only become even because operation is +-2
    long long makeSimilar(vector<int>& nums, vector<int>& tar) {
        sort(nums.begin(), nums.end());
        sort(tar.begin(), tar.end());
        
        vector<int> odd, even, oddtar, eventar;
        
        for(int i=0;i<nums.size();i++){
            if((nums[i]&1)==0)even.push_back(nums[i]);
            else    odd.push_back(nums[i]);
            
            if((tar[i]&1) == 0)eventar.push_back(tar[i]);
            else    oddtar.push_back(tar[i]);
        }
        
        long long ans=0;
        
        for(int i=0;i<even.size();i++){
            ans += abs(even[i] - eventar[i])/2;
        }
        for(int i=0;i<odd.size();i++){
            ans += abs(odd[i] - oddtar[i])/2;
        }
        
        return ans/2;
    }
};