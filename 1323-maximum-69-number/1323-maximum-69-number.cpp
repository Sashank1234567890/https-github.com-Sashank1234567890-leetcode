class Solution
{
    public:
        int maximum69Number(int num)
        {
            string s = to_string(num);
            auto it = find_if(s.begin(), s.end(), [](char c)
            {
                return c == '6';
	});

            if (it != s.end())
                *it = '9';

            return stoi(s);
        }
};