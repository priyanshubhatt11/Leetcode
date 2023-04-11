class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        reverse(num.begin(), num.end());
        vector<int> ans;
        int idx = 0;
        int c =0;
        while(idx < num.size() || c>0 || k!=0){
            int temp = k%10;
            k = k/10;
            int x;
            if(idx < num.size()){
                x = (num[idx] + c + temp);
                idx++;
            }
            else{
                x = temp +c;
            }
            
            c = x/10;
            x = x%10;
            ans.push_back(x);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};