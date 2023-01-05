class Solution {
public:
    int findRadius(vector<int>& h, vector<int>& heat) {
        sort(h.begin(), h.end());
        sort(heat.begin(), heat.end());
        int n = h.size();
        vector<int> vec(n,INT_MAX);
        int x=0;
        for(int i=0;i<n &&x<heat.size();i++){
            if(h[i] <= heat[x]){
                vec[i] = heat[x] - h[i];    // minimum in left side
            }
            else{
                x++;
                i--;
            }
            
        }
        x = heat.size()-1;
        for(int i=n-1;i>=0 && x>=0;i--){
            if(h[i] >= heat[x]){
                vec[i] = min(vec[i], h[i] - heat[x]);
            }
            else{
                i++;
                x--;
            }
        }
        return *max_element(vec.begin(), vec.end());
    }
};