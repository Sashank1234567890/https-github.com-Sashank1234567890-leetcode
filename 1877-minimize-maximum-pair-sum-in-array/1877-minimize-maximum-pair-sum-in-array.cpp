class Solution {
public:
    int minPairSum(vector<int>& nums) {

        const int MAX = 100000;

        vector<int> freq(MAX + 1, 0);

        for (int x : nums)
            freq[x]++;

        int i = 0;
        int j = MAX;

        int ans = 0;

        while (i <= j) {

            while (i <= j && freq[i] == 0)
                i++;

            while (i <= j && freq[j] == 0)
                j--;

            if (i > j)
                break;

            ans = max(ans, i + j);

            freq[i]--;
            freq[j]--;
        }

        return ans;
    }
};