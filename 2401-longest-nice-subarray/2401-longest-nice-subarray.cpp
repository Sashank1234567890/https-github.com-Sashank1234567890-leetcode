class Solution {
public:
    bool conflict(int cnt[], int x) {

        for(int b = 0; b < 32; b++) {
            if((x & (1 << b)) && cnt[b] > 0)
                return true;
        }

        return false;
    }

    void add(int cnt[], int x) {

        for(int b = 0; b < 32; b++) {
            if(x & (1 << b))
                cnt[b]++;
        }
    }

    void remove(int cnt[], int x) {

        for(int b = 0; b < 32; b++) {
            if(x & (1 << b))
                cnt[b]--;
        }
    }

    int longestNiceSubarray(vector<int>& nums) {

        int cnt[32] = {0};

        int i = 0;
        int ans = 0;

        for(int j = 0; j < nums.size(); j++) {

            while(conflict(cnt, nums[j])) {
                remove(cnt, nums[i]);
                i++;
            }

            add(cnt, nums[j]);

            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};