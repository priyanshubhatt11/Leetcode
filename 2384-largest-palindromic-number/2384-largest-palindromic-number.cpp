class Solution {
public:
    
//     num = "444947137"
// Output: "7449447"
    string largestPalindromic(string num) {
        unordered_map<int ,int> map;
        
        for(char i: num){
            map[i-'0']++;
        }
        string front= "", back = "";
        
        for(int i=9;i>=0;i--){  // for character appearing more than or equal to 2 times
            if(i== 0 && front.size() == 0)continue;
            
            while(map[i] > 1){
                front += to_string(i);
                back += to_string(i);
                map[i] -= 2;
            }
        }
        
        for(int i=9;i>=0;i--){  // for middle character;
            if(map[i] > 0){
                front += to_string(i);
                break;
            }
        }
        
        reverse(back.begin(), back.end());
        return front + back;
       
        
    }
};