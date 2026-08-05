class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {

        long long sum = 0;

        for(auto it : chalk)
            sum += it;

        k %= sum;

        for(int i = 0; i < chalk.size(); i++) {

            if(k < chalk[i])
                return i;

            k -= chalk[i];
        }

        return 0;
    }
};