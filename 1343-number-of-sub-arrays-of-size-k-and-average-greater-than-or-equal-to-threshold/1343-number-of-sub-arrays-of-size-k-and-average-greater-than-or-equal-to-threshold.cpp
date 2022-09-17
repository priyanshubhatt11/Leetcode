class Solution {
public:
    int numOfSubarrays(vector<int>& num, int k, int th) {
        int sum=0,ans=0;
        for(int i=0;i<k;i++){
            sum += num[i];
        }
        for(int i=k;i<num.size();i++){
            if(sum/k >= th)ans++;
            int j = i-k;
            sum += num[i];
            sum -= num[j];
        }
        if(sum/k >= th) ans++;
        return ans;
    }
};