class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int,int> mp;
        for(auto i:nums){
            if(i>=0 || i%value == 0){
                mp[i%value]++;
            }
            else{
                int temp = abs(i);
                if(temp == value){
                    mp[0]++;
                }
                else{
                    temp = i + (temp/value)*value + value;
                    //cout<<temp<<" ";
                    mp[temp]++;
                }
            }
            
            //cout<<abs(i)%value<<" ";
            
        }
        //for(auto i:mp)cout<<i.first<<" ";
        
        int c=0;
        while(true){
            if(mp.count(c) == false){
                return c;
            }
            if(mp[c]>1){
                mp[c+value] = mp[c]-1;
            }
            c++;
        }
        return 0;
    }
};