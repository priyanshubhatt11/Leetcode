class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int carry = 0;
        bool flag = false;
        reverse(num.begin(), num.end());
        for(int i=0;i<num.size();i++){
            int x = k%10;
            k = k/10;
            int sum = num[i] + x; 
            //cout<<num[i]<<" "<<x<<" ";
            if(flag == true){
                sum++;
                flag =false;
            }
            if(sum > 9){
                sum = sum%10;
                flag = true;
            }
            
            num[i] = sum;
        }
        
        //for(auto i:num)cout<<i<<" ";
        while(k!=0){
            int x = k%10;
            if(flag){
                x++;
                flag = false;
            }
            if(x>9){
                flag= true;
                x = x%10;
            }
            num.push_back(x);
            k = k/10;
        }
        if(flag)num.push_back(1);
        reverse(num.begin(), num.end());
        return num;
    }
};