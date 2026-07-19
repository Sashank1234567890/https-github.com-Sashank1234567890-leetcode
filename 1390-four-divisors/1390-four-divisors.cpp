class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {

        int MAX = *max_element(nums.begin(), nums.end());

        vector<int> cnt(MAX + 1, 0);
        vector<int> sum(MAX + 1, 0);

        for(int i = 1; i <= MAX; i++) {
            for(int j = i; j <= MAX; j += i) {
                
                if(cnt[j]<5){
                cnt[j]++;
                sum[j] += i;
                }
            }
        }

        int ans = 0;

        for(int x : nums) {
            if(cnt[x] == 4)
                ans += sum[x];
        }

        return ans;
    }
};