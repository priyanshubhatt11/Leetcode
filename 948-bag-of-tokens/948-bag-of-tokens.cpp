class Solution 
{
public:
    int bagOfTokensScore(vector<int>& tokens, int power) 
    {
        std::sort(tokens.begin(), tokens.end());
        
        int left = 0, right = tokens.size() - 1;
        int res = 0;
        int cur = 0;
        
        while (left <= right)
        {
            if (power >= tokens[left])
            {
                cur++;
                power -= tokens[left];
                left++;
            }
            else
            {
                if (cur <= 0)
                    break;
                
                cur--;
                power += tokens[right];
                right--;
            }
            
            res = std::max(res, cur);
        }
        
        return res;
    }
};