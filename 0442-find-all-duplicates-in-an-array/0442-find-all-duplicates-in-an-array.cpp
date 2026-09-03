class Solution
{
    public:
        vector<int> findDuplicates(vector<int> &nums)
        {
            vector<int> dup;
            int n=nums.size();
            for (int i = 0; i < n; i++)
            {
                int val = nums[i];
                if (nums[abs(val)-1] < 0)
                    dup.push_back(abs(val));
                else
                {
                    nums[abs(val)-1] = -nums[abs(val)-1];
                }
            }
            return dup;
        }
};