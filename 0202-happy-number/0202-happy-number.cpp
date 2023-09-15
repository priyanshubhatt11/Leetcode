class Solution {
public:
    int solve(int x){
        int sum =0;
        while(x!=0){
            int temp = x%10;
            sum += temp*temp;
            x /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        // we use here the concept of slow and fast pointer or we can do it with hash table
        int slow, fast;
        slow = fast = n;
        do{
            slow = solve(slow);
            fast = solve(fast);
            fast = solve(fast);
        }while(slow != fast); // loop breaks when slow == fast because slow or fast will remains 1 if it once reached sum = 1 // EX- 100 => 1*1 + 0*0 + 0*0;
        
        if(slow == 1)return true;
        return false;
    }
};