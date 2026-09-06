class Solution
{
    public:
        struct trienode
        {
            bool isEnd;
            trienode *child[26];
            int cnt;
            trienode()
            {
                for (int i = 0; i < 26; i++)
                {
                    child[i] = NULL;
                }
                isEnd = 0;
                cnt = 0;
            }
        };

    void insert(trienode *root, string &word)
    {
        trienode *crawl = root;
        for (char &x: word)
        {
            int idx = x - 'a';
            if (crawl->child[idx] == NULL)
            {
                crawl->child[idx] = new trienode();
            }
            
            crawl = crawl->child[idx];
            crawl->cnt++;
        }
        crawl->isEnd = 1;
    }
    int score(trienode *root, string &word)
    {   trienode *crawl = root;
        int val = 0;
        for (char &x: word)
        {
            int idx = x - 'a';          
            if (crawl->child[idx] == NULL)
            {
                return val;
            }
            
            crawl = crawl->child[idx];
            val += crawl->cnt; 
        }
        return val;
    }
    vector<int> sumPrefixScores(vector<string> &words)
    {
        trienode *root = new trienode();
        for (string &s: words)
        {
            insert(root, s);
        }
        vector<int> ans;
        for (string &s: words)
        {
            ans.push_back(score(root, s));
        }
        return ans;
    }
};