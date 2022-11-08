class Solution {
public:
    vector<int> fairCandySwap(vector<int>& a, vector<int>& b) {
        int sum1=0,sum2=0;
        unordered_set<int> set1, set2;
        for(int i:a){
            sum1+=i;
            set1.insert(i);
        }
        for(int i:b){
            sum2+=i;
            set2.insert(i);
        }
        int avg = (sum1-sum2)/2;
        
        for(auto i:set1){
            if(set2.find(i - avg) != set2.end()){
                return {i, i-avg};
            }
        }
        return {0,0};
    }
};