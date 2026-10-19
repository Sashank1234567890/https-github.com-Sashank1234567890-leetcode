class Solution
{
    public:
        int upper_bound(vector<int> &nums, int &tar)
        {
            int l = 0, h = nums.size() - 1;
            int ans = nums.size();

            while (l <= h)
            {
                int mid = l + (h - l) / 2;

                if (nums[mid] <= tar)
                    l = mid + 1;
                else
                {
                    ans = mid;
                    h = mid - 1;
                }
            }

            return ans;
        }

    int lower_bound(vector<int> &nums, int &tar)
    {
        int l = 0, h = nums.size() - 1;
        int ans = nums.size();

        while (l <= h)
        {
            int mid = l + (h - l) / 2;

            if (nums[mid] < tar)
                l = mid + 1;
            else
            {
                ans = mid;
                h = mid - 1;
            }
        }

        return ans;
    }
    vector<int> targetIndices(vector<int> &nums, int target)
    {
        ranges::sort(nums);
        vector<int> ans;
        int r = upper_bound(nums, target);
        int l = lower_bound(nums, target);
        cout << l << " " << r;
        if (l == nums.size())
        {
            return {};
        }

        for (int i = l; i < r; i++)
        {
            ans.push_back(i);
        }
        return ans;
    }
};