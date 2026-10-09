class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        int result = 0; //insertions

        int count = 0;
        int i = 0;

        while(i < n) {
            if(s[i] == '(') {
                count++;
                i++;
            } else { 
                if(count > 0) {//checking opening hai ya nhi
                    count--;
                } else {
                    result++; 
                }

                if(i+1 < n && s[i+1] == ')') {//uska agla closing hai ya nhi
                    i += 2;
                } else {
                    result++; 
                    i++;
                }
            }
        }

        return result + count*2;
    }
};
