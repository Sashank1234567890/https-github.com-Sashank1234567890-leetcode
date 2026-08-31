class Solution {
public:
    bool isPerfectSquare(int x) {      
        if(x == 0)
            return 1;
        
        long long a = x;
        
        while(true) {
            
            long long next = (a + x / a) / 2;
            
            if(next >= a)
                break;
            
            a = next;
        }
        
        return a*a==x;
    }
};