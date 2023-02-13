class Solution {
public:
    
    vector<string> ans;
    void solve(string digits,string map[] ,string output, int idx){
        
        if(idx >= digits.size()){
            ans.push_back(output);
            return;
        }
        int num = digits[idx] - '0';
        string val = map[num];
        
        for(int i=0;i<val.size();i++){
            output.push_back(val[i]);
            solve(digits,map, output,idx +1);
            output.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0)return {};
        string map[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        solve(digits, map,"", 0);
        return ans;
    }
};