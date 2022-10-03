class Solution {
public:
    int minCost(string col, vector<int>& nt) {
        int ans= 0;
        for(int i=0;i<col.size();i++){
            int j= i;
            int temp =0;
            int mm = 0;
            while(j<col.size() && col[i] == col[j]){
                //cout<<col[j]<<" ";
                mm += nt[j];
                temp = max(temp, nt[j]);
                j++;
            }
            ans +=  mm - temp;
            i =j-1;
            // i=j-1;
            
        }
        return ans;
    }
};