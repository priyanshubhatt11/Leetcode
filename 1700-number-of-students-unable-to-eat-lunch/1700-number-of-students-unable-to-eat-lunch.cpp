class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        
        queue<int> q;
        for(int i:students){
            q.push(i);
        }
        
        reverse(sandwiches.begin(), sandwiches.end());
        stack<int> s;
        for(int i:sandwiches){
            s.push(i);
        }
        int i=0;
        while(i<q.size()){
            if(s.top() == q.front()){
                s.pop();
                q.pop();
                i=0;
            }
            else{
                int k = q.front();
                i++;
                q.pop();
                q.push(k);
            }
        }
        return q.size();
        
    
        
    }
};