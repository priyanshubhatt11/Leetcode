class Solution {
public:
    int earliestFullBloom(vector<int>& pt, vector<int>& gt) {
        vector<pair<int,int>> vec;
        for(int i=0;i<pt.size();i++){
            vec.push_back({gt[i], pt[i]});
        }
        sort(vec.rbegin(), vec.rend());
        
        int ans =0 , start=0;
        for(auto i:vec){
            start += i.second;
            ans =  max(ans, start + i.first);
        }
        return ans;
    }
};