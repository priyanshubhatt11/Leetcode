class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int,int> mp;
        for(auto i:nums){
            if(i>=0 || i%value == 0){
                mp[i%value]++;
            }
            else{ // negative
                mp[i%value + value]++;
            }
        }
        
        int c =0;
        while(true){
            if(mp.count(c) == false)return c;
            
            if(mp[c]>1){
                mp[c+value] = mp[c]-1;
            }
            c++;
        }
        return 0;
    }
};