class Solution {
public:
    //  n = 5, edges = [[1,2],[2,3],[3,4],[4,2],[1,4],[2,5]]
    
    bool isPossible(int n, vector<vector<int>>& edges) {
        
        vector<set<int>> ff(n+1);
        vector<int> od(n+1, 0);
        for(auto i:edges){
            od[i[0]]++;
            od[i[1]]++;
            ff[i[0]].insert(i[1]);
            ff[i[1]].insert(i[0]);
        }
        vector<int> odd;
        for(int i=1;i<od.size();i++){
            if(od[i]%2 !=0 ) odd.push_back(i);
        }
        
        
        int m = odd.size();
        
        // when we connect two node first we have to check if its not already connected
        
        if(m==0)return true;
        if(m == 2){
            // if(ff[odd[0]].find(odd[1]) == ff[odd[0]].end() && ff[odd[1]].find(odd[0]) == ff[odd[1]].end() )return true;
            for(int i=1;i<=n;i++)
            {
                if(ff[odd[0]].find(i) == ff[odd[0]].end() && ff[odd[1]].find(i) ==ff[odd[1]].end())
                    return true;
            }
        }        
        if(m == 4){
            if(ff[odd[0]].find(odd[1]) == ff[odd[0]].end() && ff[odd[2]].find(odd[3]) == ff[odd[2]].end())return true;
            if(ff[odd[0]].find(odd[2]) == ff[odd[0]].end() && ff[odd[1]].find(odd[3]) == ff[odd[1]].end())return true;
            if(ff[odd[0]].find(odd[3]) == ff[odd[0]].end() && ff[odd[1]].find(odd[2]) == ff[odd[1]].end())return true;
        }
    
        return false;
        
    }
};