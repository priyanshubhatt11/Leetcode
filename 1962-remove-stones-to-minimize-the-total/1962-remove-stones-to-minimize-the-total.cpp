class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        multiset<int, greater<int>> s;
        for(int i:piles){
            s.insert(i);
        }
        while(k--){
            int x = *s.begin();
            x = ceil(x/2.0);
            s.erase(s.lower_bound(*s.begin()));  // delete only one element
            s.insert(x);
        }
        int ans=0;
        
        for(auto i:s){
            ans+=i;
        }
        return ans;
    }
};