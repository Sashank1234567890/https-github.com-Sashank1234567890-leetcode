class Solution
{
    public:
        string customSortString(string order, string str)
        {
            int count[26] = { 0 };

            for (char &x: str)
                count[x - 'a']++;

            string result = "";
            for (char &ch: order)
            {
                while (count[ch - 'a']--)
                {
                    result.push_back(ch);
                }
            }

            for (char &ch: str)
            {
                if (count[ch - 'a'] > 0)
                {
                    result.push_back(ch);
                }
            }

            return result;
        }
};