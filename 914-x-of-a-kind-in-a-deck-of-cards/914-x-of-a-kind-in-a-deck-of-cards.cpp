class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int> map;
        for(int i:deck){
            map[i]++;
        }
        int mm=INT_MAX;
        
        for(auto i:map){
            mm = min(mm, i.second);
        }
        
        int ans=0;
        if(mm <2)return false;
        
        for(int i=mm;i>=2;i--){
            ans=0;
            for(auto j:map){
                if(j.second %i == 0)ans++;
                else    break;
            }
            if(ans == map.size())return true;
        }
        return false;
        
    }
};