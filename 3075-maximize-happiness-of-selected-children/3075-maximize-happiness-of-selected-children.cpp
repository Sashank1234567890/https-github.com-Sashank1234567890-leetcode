class Solution
{
    public:
        long long maximumHappinessSum(vector<int> &happiness, int k)
        {

            priority_queue<int, vector < int>, greater < int>> pq;

            for (int x: happiness)
            {
                if (pq.size() < k)
                    pq.push(x);
                else if (x > pq.top())
                {
                    pq.pop();
                    pq.push(x);
                }
            }

            long long ans = 0;
            int count = k - 1;

            while (!pq.empty())
            {
                ans += max(0, pq.top() - count);
                pq.pop();
                count--;
            }

            return ans;
        }
};