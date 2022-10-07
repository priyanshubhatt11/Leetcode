class MyCalendarThree {
public:
    map<int,int>mp;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int sum=0,ans=0;
        for(auto &it:mp)
        {
            sum+=it.second;
            ans=max(ans,sum);
        }
        return ans;
    }
};