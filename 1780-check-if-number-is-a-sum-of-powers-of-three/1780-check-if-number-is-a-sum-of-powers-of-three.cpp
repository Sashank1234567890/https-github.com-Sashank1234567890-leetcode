class Solution {
public:
    bool checkPowersOfThree(int n) {
        while(n > 0) {
            if(n%3 == 2) {//ternary representation
                return false;
            }

            n = n/3;
        }

        return true;
    }
};