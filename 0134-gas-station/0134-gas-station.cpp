class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gsum=0, sum=0;
        for(auto i:gas)gsum += i;
        for(auto i:cost)sum+=i;
        if(sum > gsum)return -1;
        int bal =0;
        int idx=0;
        for(int i=0;i<gas.size();i++){
            bal += gas[i] - cost[i];
            if(bal < 0){
                idx = i+1;
                bal =0;
            }
        }
        return idx;
    }
};