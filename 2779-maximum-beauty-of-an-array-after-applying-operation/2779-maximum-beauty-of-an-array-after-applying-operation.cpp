class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        vector<pair<int, int>> ranges;
        for (int num : nums) {
            ranges.push_back({num - k, num + k});
        }

        sort(ranges.begin(), ranges.end());

        int maxBeauty = 0;
        deque<int> deq; 

        
        for (const auto& range : ranges) {
            while (!deq.empty() && deq.front() < range.first) {
                deq.pop_front();
            }

            deq.push_back(range.second);

            maxBeauty = max(maxBeauty, (int)deq.size());
        }

        return maxBeauty;
    }
};

