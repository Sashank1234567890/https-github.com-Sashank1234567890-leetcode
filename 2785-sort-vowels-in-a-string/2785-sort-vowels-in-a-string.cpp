class Solution
{
    public:
        bool isvowel(char x)
        {
            return x == 'a' || x == 'A' || x == 'e' || x == 'E' || x == 'i' || x == 'I' || x == 'o' || x == 'O' || x == 'u' || x == 'U';
        }

    void merge(string &s, int l, int mid, int r)
    {

        vector<char> left, right;

        for (int i = l; i <= mid; i++)
            if (isvowel(s[i]))
                left.push_back(s[i]);

        for (int i = mid + 1; i <= r; i++)
            if (isvowel(s[i]))
                right.push_back(s[i]);

        int i = 0;
        int j = 0;
        vector<char> temp;

        while (i < left.size() && j < right.size())
        {
            if (left[i] <= right[j])
                temp.push_back(left[i++]);
            else
                temp.push_back(right[j++]);
        }

        while (i < left.size())
            temp.push_back(left[i++]);

        while (j < right.size())
            temp.push_back(right[j++]);

        int k = 0;

        for (int i = l; i <= r; i++)
        {
            if (isvowel(s[i]))
                s[i] = temp[k++];
        }
    }

    void mergesort(string &s, int l, int r)
    {

        if (l >= r)
            return;

        int mid = l + (r - l) / 2;

        mergesort(s, l, mid);
        mergesort(s, mid + 1, r);

        merge(s, l, mid, r);
    }

    string sortVowels(string s)
    {

        mergesort(s, 0, s.size() - 1);

        return s;
    }
};