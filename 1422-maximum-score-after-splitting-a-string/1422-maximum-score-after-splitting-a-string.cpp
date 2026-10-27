class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        int result = INT_MIN;

        
        int zeros = 0;
        int ones  = 0;
        
        for(int i = 0; i < n-1; i++) {
            if(s[i] == '1') {
                ones++;
            } else {
                zeros++;
            }
            
            result = max(result, zeros - ones);
        }
        
        if(s[n-1] == '1') {
            ones++;
        }
        
        return result+ones;
    }
};
