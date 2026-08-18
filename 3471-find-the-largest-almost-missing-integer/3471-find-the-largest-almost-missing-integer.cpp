class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        unordered_map<int,int> subcnt;

        int n = nums.size();

        for(int i = 0; i < k; i++) {
            freq[nums[i]]++;
        }

        for(auto it : freq) {
            subcnt[it.first]++;
        }

        for(int i = k; i < n; i++) {
            freq[nums[i-k]]--;

            if(freq[nums[i-k]] == 0) {
                freq.erase(nums[i-k]);
            }

            freq[nums[i]]++;

            for(auto it : freq) {
                subcnt[it.first]++;
            }
        }

        int ans = -1;

        for(auto it : subcnt) {
            if(it.second == 1) {
                ans = max(ans, it.first);
            }
        }

        return ans;
    }
};