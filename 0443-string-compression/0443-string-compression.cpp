class Solution
{
public:
    int compress(vector<char> &chars)
    {
        unordered_map<int, int> freq;

        int n = chars.size();
        int count = 1;
        int start = 0;

       
        for (int i = 1; i < n; i++)
        {
            if (chars[i] == chars[i - 1])
            {
                count++;
            }
            else
            {
                freq[start] = count;
                start = i;
                count = 1;
            }
        }

        // Last group
        freq[start] = count;

        vector<char> ans;

        for (int i = 0; i < n;)
        {
            ans.push_back(chars[i]);

            int f = freq[i];

            if (f > 1)
            {
                string s = to_string(f);

                for (char c : s)
                    ans.push_back(c);
            }

            i += f;
        }

        for (int i = 0; i < ans.size(); i++)
            chars[i] = ans[i];

        return ans.size();
    }
};