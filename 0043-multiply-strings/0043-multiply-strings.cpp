class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")return "0";
        int n1 = num1.size(), n2 = num2.size();
        vector<int> vec(n1+n2, 0);
        
        for(int i=n1-1;i>=0;i--){
            for(int j=n2-1;j>=0;j--){
                
                int x = (num1[i] - '0') * (num2[j] - '0');
                vec[i+j+1] += x;
                vec[i+j] += vec[i+j+1]/10;
                vec[i+j+1] %= 10;
                
            }
        }
        // for(int i:vec)cout<<i<<" ";
        int i=0;
        while(i<vec.size() && vec[i] == 0)i++;
        string ans = "";
        for(int j=i;j<vec.size();j++){
            ans.push_back(vec[j] + '0');
        }
        return ans;
       
    }
};