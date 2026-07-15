class Solution
{
    public:
        int bestRotation(vector<int> &nums)
        {

            int n = nums.size();

            vector<int> diff(n, 0);

            for (int i = 0; i < n; i++)
            {

                int l = (i + 1) % n;
                int r = (i - nums[i] + n) % n;

                if (l <= r)
                {

                    diff[l]++;

                    if (r + 1 < n)
                        diff[r + 1]--;
                }
                else
                {

                    diff[0]++;

                    if (r + 1 < n)
                        diff[r + 1]--;

                    diff[l]++;

                    // diff[n]--;//uneccsary with and without padding
                }
            }

            int ans = 0;
            int score = 0;
            int mx = -1;

            for (int i = 0; i < n; i++)//only n-1 tak hi matlab hai array n bhi ho to
            {

                score += diff[i];

                if (score > mx)
                {

                    mx = score;
                    ans = i;
                }
            }

            return ans;
        }
};