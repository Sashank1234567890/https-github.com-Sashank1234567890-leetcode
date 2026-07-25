class Solution
{
    public:
        int leastInterval(vector<char> &tasks, int n)
        {
            vector<int> freq(26, 0);
            int cnt = 0;
            for (char &x: tasks)
            {
                freq[x - 'A']++;
                cnt = max(cnt, freq[x - 'A']);
            }
            int ans = (cnt - 1) *(n + 1);
            for (int x: freq)
            {
                if (cnt == x)
                    ans++;
            }
            return ans > tasks.size() ? ans : (int) tasks.size();
        }
};