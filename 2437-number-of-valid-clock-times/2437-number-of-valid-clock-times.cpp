class Solution {
public:
    int countTime(string t) {
        int ans1 = 1, ans2 = 1;
                
        
        if(t[0] == '?'){
            if(t[1] == '?')ans1 = 24;
            else if(t[1]-'0' > 3) ans1 = 2;
            else ans1 = 3;
        }
        else if(t[1] == '?'){
            if(t[0]-'0' >= 2)ans1 = 4;
            else ans1 = 10;
        }
        if(t[3] == '?'){
            if(t[4] == '?')
                ans2 = 60;
            // else if(t[4]-'0' == 0)ans2 = 7;
            else ans2 = 6;
        }
        else if(t[4] == '?'){
            
            ans2 = 10;
        }
        //cout<<ans1<<" "<<ans2;
        return ans1 * ans2;
    
    }
};























