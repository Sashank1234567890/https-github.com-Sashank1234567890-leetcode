class Solution {
public:
    
    bool check(string &word, int i, int n) {
        return word.substr(i, n-i) == word.substr(0, n-i);
    }
    
    int minimumTimeToInitialState(string word, int k) {
        int n = word.length();
        
        int count = 1;
        int i = k;
        
        while(i < n) {
            
            if(check(word, i, n)) {
                break;
            }
            
            count++;
            i += k;
            
        }
        
        return count;
        
    }
};

