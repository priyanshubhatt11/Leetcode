class Solution {
public:
    int candy(vector<int>& rate) {
        int n = rate.size();
        vector<int> left(n,1), right(n,1);
        for(int i=1;i<n;i++){
            if(rate[i] > rate[i-1]){
                left[i] = left[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(rate[i] > rate[i+1]){
                right[i] = right[i+1] + 1;
            }
        }
        int sum =0;
        for(int i=0;i<n;i++){
            sum += max(left[i], right[i]);
        }
        return sum;
    }
};