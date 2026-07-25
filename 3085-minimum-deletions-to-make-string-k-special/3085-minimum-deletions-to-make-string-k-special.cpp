class Solution
{
    public:
        int minimumDeletions(string word, int k)
        {
            vector<int> freq(26, 0);

            for (char &ch: word)
            {
                freq[ch - 'a']++;
            }

            sort(begin(freq), end(freq));

            int result = INT_MAX;
            int deleted_till_now = 0;

            for (int i = 0; i < 26; i++)
            {

                int minFreq = freq[i];
                int temp = deleted_till_now;

                for (int j = 25; j > i; j--)
                {
                    if (freq[j] - freq[i] <= k)
                        break;

                    temp += freq[j] - minFreq - k;
                }

                result = min(result, temp);
                deleted_till_now += minFreq;
            }

            return result;
        }
};