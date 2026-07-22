class Solution {
public:
    
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        
        sort(begin(nums), end(nums));
        
        int m = queries.size();
        vector<int> result;
        
        for(int  &query : queries) {
            int sum = 0;
            
            for(int j = 0; j<n; j++) {
                sum += nums[j];
                if(sum > query) {
                    result.push_back(j);
                    break;
                }
                
                if(j == n-1) {
                    result.push_back(n);
                }
            }  
        }
        return result;
    }
};