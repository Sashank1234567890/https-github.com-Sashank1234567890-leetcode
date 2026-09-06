class Solution
{
public:
    string removeOccurrences(string s, string part)
    {
        string ans = "";
        int l = part.size();

        for(char x : s)
        {
            ans.push_back(x);

            if(ans.size() >= l)
            {
                bool remove = 1;

                for(int j = ans.size()-l; j < ans.size(); j++)
                {
                    if(ans[j] != part[j-(ans.size()-l)])
                    {
                        remove = 0;
                        break;
                    }
                }

                if(remove)
                {
                    for(int j = 0; j < l; j++)
                    {
                        ans.pop_back();
                    }
                }
            }
        }

        return ans;
    }
};