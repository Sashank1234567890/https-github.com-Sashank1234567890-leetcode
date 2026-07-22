class Solution
{
    public:
        vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
        {

            unordered_set<string> st(words.begin(), words.end());

            vector<string> ans;

            for (string &word: words)
            {

                st.erase(word);

                int n = word.size();

                vector<bool> dp(n + 1, false);//i length tak ka prefix hai ya nhi

                dp[0] = true;//empty to hoga hi

                for (int i = 1; i <= n; i++)
                {

                    for (int j = 0; j < i; j++)
                    {

                        if (!dp[j])
                            continue;

                        if (st.count(word.substr(j, i - j)))
                        {
                            dp[i] = true;
                            break;
                        }
                    }
                }

                if (dp[n])
                    ans.push_back(word);

                st.insert(word);
            }

            return ans;
        }
};