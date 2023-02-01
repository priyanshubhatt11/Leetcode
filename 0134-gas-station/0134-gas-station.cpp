class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int bal =0;
        int idx = 0;
        int gsum =0, sum=0;
        for(int i:gas)gsum+=i;
        for(int i:cost)sum+=i;
        if(sum > gsum)return -1;
        for(int i=0;i<gas.size();i++){
            bal += gas[i] - cost[i];
            if(bal <0){
                idx = i+1;
                bal =0;
            }
        }
        return idx;
        
    }
};