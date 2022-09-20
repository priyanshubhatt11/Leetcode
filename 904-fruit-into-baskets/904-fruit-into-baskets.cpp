class Solution {
public:
    int totalFruit(vector<int>& fr) {
        int ans=0,c=0,j=0;
        unordered_map<int,int> map;
        for(int i=0;i<fr.size();i++){
            map[fr[i]]++;
            
            if(map.size() <= 2){
                c = i -j +1;
                ans = max(ans, c);
            }
            
            while(map.size() > 2){
                map[fr[j]]--;
                if(map[fr[j]] == 0)map.erase(fr[j]);
                j++;
            }           
            
        }
        return ans;
        
    }
};