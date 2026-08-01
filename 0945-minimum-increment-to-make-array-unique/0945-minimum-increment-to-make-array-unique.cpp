class Solution
{
    public:
        int minIncrementForUnique(vector<int> &nums)
        {
            int n = nums.size();
            int maxElement = 0;
            int moves = 0;

            for (int val: nums)
            {
                maxElement = max(maxElement, val);
            }

            vector<int> count(n + maxElement, 0);

            for (int val: nums)
            {
                count[val]++;
            }

            for (int i = 0; i < count.size(); i++)
            {
                if (count[i] <= 1) continue;

                int extra = count[i] - 1;
                count[i + 1] += extra;
                count[i] = 1;
                moves += extra;
            }

            return moves;
        }
};