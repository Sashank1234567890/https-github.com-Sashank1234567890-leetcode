class Solution {
public:
    string removeStars(string s) {

        int i = 0;

        for(char x : s) {

            if(x == '*') {
                i--;
            }
            else {
                s[i] = x;
                i++;
            }
        }

        s.resize(i);

        return s;
    }
};