class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int idx=0;
        int gsum=0,sum=0;
        for(auto i:gas)gsum+=i;
        for(auto i:cost)sum+=i;
        if(gsum-sum <0)return -1;
        
        int bal =0;
        for(int i=0;i<gas.size();i++){
            bal += gas[i] - cost[i];
            cout<<bal<<" ";
            if(bal <0){
                idx = i+1;
                bal =0;
            }
            
        }
        return idx;
    }
};