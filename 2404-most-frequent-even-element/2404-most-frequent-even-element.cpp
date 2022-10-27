class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int,int> map;      // map stores key in sorted order
        for(int i:nums){
            if(i%2 == 0){
                map[i]++;
            }
        }
        int ans = -1, mx =0;
        for(auto i:map){
            if(i.second > mx){
                mx = i.second;
                ans = i.first;
            }
        }
        
        return ans;
    }
};