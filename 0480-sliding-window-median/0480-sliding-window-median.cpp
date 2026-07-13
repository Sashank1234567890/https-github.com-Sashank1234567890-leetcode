class Solution
{
    public:
        multiset<int> left, right;

    vector<double> medianSlidingWindow(vector<int> &nums, int k)
    {

        vector<double> ans;

        for (int i = 0; i < nums.size(); i++)
        {

            if (left.empty() || nums[i] <= *prev(left.end()))
                left.insert(nums[i]);
            else
                right.insert(nums[i]);

            if (left.size() > right.size() + 1)
            {
                auto it = prev(left.end());
                right.insert(*it);
                left.erase(it);
            }

            if (right.size() > left.size())
            {
                auto it = right.begin();
                left.insert(*it);
                right.erase(it);
            }

            if (i >= k)
            {

                auto it = left.find(nums[i - k]);

                if (it != left.end())
                    left.erase(it);
                else
                    right.erase(right.find(nums[i - k]));

                if (left.size() > right.size() + 1)
                {
                    auto it = prev(left.end());
                    right.insert(*it);
                    left.erase(it);
                }

                if (right.size() > left.size())
                {
                    auto it = right.begin();
                    left.insert(*it);
                    right.erase(it);
                }
            }

            if (i >= k - 1)
            {

                if (k % 2)
                    ans.push_back(*prev(left.end()));
                else
                    ans.push_back(((double) *prev(left.end()) + *right.begin()) / 2.0);
            }
        }

        return ans;
    }
};