class Solution
{
    public:
        int longestSubarray(vector<int> &nums, int limit)
        {
            int n = nums.size();

            deque<int> mndq, mxdq;

            int i = 0;
            int j = 0;
            int maxLength = 0;

            while (j < n)
            {
                int val = nums[j];

                while (!mndq.empty() && nums[mndq.back()] > val)
                {
                    mndq.pop_back();
                }

                while (!mxdq.empty() && nums[mxdq.back()] < val)
                {
                    mxdq.pop_back();
                }

                mndq.push_back(j);
                mxdq.push_back(j);

                while (!mndq.empty() && !mxdq.empty() &&
                    nums[mxdq.front()] - nums[mndq.front()] > limit)
                {
                    i = min(mndq.front(), mxdq.front()) + 1;

                    while (!mndq.empty() && mndq.front() < i)
                    {
                        mndq.pop_front();
                    }

                    while (!mxdq.empty() && mxdq.front() < i)
                    {
                        mxdq.pop_front();
                    }
                }

                maxLength = max(maxLength, j - i + 1);

                j++;
            }

            return maxLength;
        }
};