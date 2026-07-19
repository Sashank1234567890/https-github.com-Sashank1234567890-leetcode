class Solution
{
    public:
        bool winnerOfGame(string colors)
        {
            int alice = 0;
            int bob = 0;

            int cnt = 1;

            for (int i = 1; i < colors.size(); i++)
            {
                if (colors[i] == colors[i - 1])
                {
                    cnt++;
                }
                else
                {
                    if (colors[i - 1] == 'A')
                        alice += max(0, cnt - 2);
                    else
                        bob += max(0, cnt - 2);

                    cnt = 1;
                }
            }

            if (colors.back() == 'A')
                alice += max(0, cnt - 2);
            else
                bob += max(0, cnt - 2);

            return alice > bob;
        }
};