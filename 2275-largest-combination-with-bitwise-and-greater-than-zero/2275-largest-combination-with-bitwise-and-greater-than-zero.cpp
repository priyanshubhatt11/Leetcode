class Solution {
public:
    int largestCombination(vector<int>& can) {
        vector<int> vec(32 ,0);
        for(int i=0;i<32;i++){
            for(int j:can){
                if(((j >>i) &1) == 1)vec[i]++;
            }
        }
        int bit=0;
        for(int i=0;i<32;i++){
            bit = max(bit, vec[i]);
        }
        return bit;
    }
};