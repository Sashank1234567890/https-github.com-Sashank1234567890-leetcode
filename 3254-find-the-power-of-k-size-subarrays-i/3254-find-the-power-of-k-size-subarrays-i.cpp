class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();

        deque<int> deq; 
        vector<int> result;

        for(int j = 0; j < n; j++) {

            if(deq.size() == k) {
                deq.pop_front(); 
            }

            if(!deq.empty() && deq.back() != nums[j]-1) { 
                deq.clear();
            }

            deq.push_back(nums[j]);

            if(j >= k-1) {
                if(deq.size() == k) {
                    result.push_back(deq.back()); 
                } else {
                    result.push_back(-1); 
                }
            }
        }

        return result;
    }
};