class Solution
{
    public:
        bool stoneGame(vector<int> &piles)
        {
            int bob = 0, alice = 0;
            int a = 1;
            int i = 0;
            int j = piles.size()-1;
            while (i <= j)
            {
                if (a)
                {
                    if (piles[i] > piles[j])
                        alice += piles[i++];
                    else
                        alice += piles[j--];
                }
                else
                {
                    if (piles[i] > piles[j])
                        bob += piles[i++];
                    else
                        bob += piles[j--];
                }
            }
            return alice > bob;
        }
};