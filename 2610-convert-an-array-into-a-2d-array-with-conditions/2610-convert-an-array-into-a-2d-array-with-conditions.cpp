class Solution
{
    public:
        vector<vector < int>> findMatrix(vector<int> &nums)
        {
            vector<vector < int>> ans;
            unordered_map<int, int> mp;
            for (auto elem: nums)
            {
                mp[elem]++;
            }
            // goes until the map size is down to 0 
            
            while (mp.size() != 0)
            {
                vector<int> need;

                for (auto &elem: mp)
                {
                    //cout<<elem.first<<" ";
                                    // pushing only one elem to the vector and decrease the map value count
                    if(elem.second <= 0)continue;
                    need.push_back(elem.first);
                    mp[elem.first]--;
                    //if(mp[elem.first] == 0)mp.erase(elem.first);
                    
                }

                                    
                if(need.size() == 0)break;

                ans.push_back(need);
            }
            return ans;
        }
};