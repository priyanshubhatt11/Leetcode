class Solution {
public:
    int maximumBags(vector<int>& c, vector<int>& r, int a) {
        for(int i=0;i<c.size();i++){
            r[i] = c[i] - r[i];
        }
        int ans =0;
        
        sort(r.begin(), r.end());
        for(int i=0;i<r.size();i++){
             a -= r[i];
             if(a>=0)ans++;
            else break;
        }
        
        return ans;
    }
};