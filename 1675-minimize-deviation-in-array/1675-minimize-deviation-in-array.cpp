class Solution {
public:
    // we can even to odd but we cant make odd to even to its original value ex 20
    int minimumDeviation(vector<int>& nums) {
        set<int> s;
        
        for(int &i:nums){
            if(i%2 != 0){   // odd
                i *= 2;
            }
            s.insert(i);
        }
        
        int ans = *s.rbegin() - *s.begin();
        while(*s.rbegin()%2 == 0){
            int x = *s.rbegin()/2;
            s.insert(x);
            s.erase(*s.rbegin());
            ans = min(ans, *s.rbegin() - *s.begin());
        }
        return ans;
        
        
    }
};