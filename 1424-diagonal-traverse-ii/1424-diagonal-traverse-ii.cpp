class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        queue<pair<int, int>> que;
        que.push({0, 0});
        vector<int> result;
        
        while (!que.empty()) {
            auto [row, col] = que.front();
            que.pop();
            result.push_back(nums[row][col]);
            
            if (col == 0 && row + 1 < nums.size()) {
                que.push({row + 1, col});
            }
            
            if (col + 1 < nums[row].size()) {
                que.push({row, col + 1});
            }
        }
        
        return result;
    }
};
