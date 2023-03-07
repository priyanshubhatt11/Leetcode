class Solution {
public:
    
    long long solve(vector<int>&time, long long mid){
        long long c =0;
        for(int i=0;i<time.size();i++){
            c += mid/time[i];
        }
        return c;
    }
    
    long long minimumTime(vector<int>& time, int tot) {
        long long l = 0, h = 1e14;
        while(l<h){
            long long mid = (l+h)/2;
            if(solve(time, mid) >= tot){
                h = mid;
            }
            else l = mid+1;
        }
        return h;
    }
};