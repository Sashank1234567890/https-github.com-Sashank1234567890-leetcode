class Solution {
public:
    
    bool check(string &word, int i) {
        int j = 0;
        
        while(i < word.length()) {
            if(word[i] == word[j]) {
                i++;
                j++;
            } else {
                break;
            }
        }
        
        return i == word.length();
    }
    
    int minimumTimeToInitialState(string word, int k) {
        int n = word.length();
        
        int count = 1;
        int i = k;
        
        while(i < n) {
            
            if(check(word, i)) {
                break;
            }
            
            count++;
            i += k;
            
        }
        
        return count;
        
    }
};
