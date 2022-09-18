class Solution {
public:
    int trap(vector<int>& hei) {
        int n = hei.size();
        vector<int> left(n),right(n);
        left[0] = hei[0];
        for(int i=1;i<hei.size();i++){
            left[i] = max(hei[i] ,left[i-1]);
        }
        
        right[n-1] = hei[n-1];
        for(int i=n-2;i>=0;i--){
            right[i] = max(hei[i] , right[i+1]);
        }
        // for(int i:left){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        // for(int i:right){
        //     cout<<i<<" ";
        // }
        int ans=0;
        for(int i=0;i<hei.size();i++){
            ans += min(left[i], right[i]) - hei[i];
        }
        return ans;
        
    }
};