class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& po, long long tar) {
        sort(po.begin(), po.end());
        vector<int> vec;
        int n = spells.size(), m= po.size();
        for(auto x:spells){
            int l = 0, h = m-1;
            while(l<=h){
                int mid = l + (h-l)/2;
                if(x * 1LL*po[mid] >= tar)h = mid-1;
                else l = mid+1;
            }
            vec.push_back(m-l);
        }
        return vec;
    }
};