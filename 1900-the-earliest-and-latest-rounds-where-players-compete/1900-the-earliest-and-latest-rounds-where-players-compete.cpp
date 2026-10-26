class Solution {
public:
    map<tuple<int,int,int>, vector<int>> dp;

    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        if (firstPlayer == n - secondPlayer + 1)
            return {1, 1};

        if (firstPlayer > n - secondPlayer + 1) {
            int temp = n - firstPlayer + 1;
            firstPlayer = n - secondPlayer + 1;
            secondPlayer = temp;
        }

        auto key = make_tuple(n, firstPlayer, secondPlayer);

        if (dp.count(key))
            return dp[key];

        int minRound = n;
        int maxRound = 1;
        int nextRoundPlayersCount = (n + 1) / 2;

        if (secondPlayer <= nextRoundPlayersCount) {
            int countLeft = firstPlayer - 1;
            int midCount = secondPlayer - firstPlayer - 1;

            for (int survivorsLeft = 0; survivorsLeft <= countLeft; survivorsLeft++) {
                for (int survivorsMid = 0; survivorsMid <= midCount; survivorsMid++) {
                    int pos1 = survivorsLeft + 1;
                    int pos2 = pos1 + survivorsMid + 1;

                    vector<int> tempResult = earliestAndLatest(nextRoundPlayersCount, pos1, pos2);

                    minRound = min(minRound, tempResult[0] + 1);
                    maxRound = max(maxRound, tempResult[1] + 1);
                }
            }
        } else {
            int fightsRight = n - secondPlayer + 1;
            int countLeft = firstPlayer - 1;
            int midCount = fightsRight - firstPlayer - 1;
            int remainMidCount = secondPlayer - fightsRight - 1;

            for (int survivorsLeft = 0; survivorsLeft <= countLeft; survivorsLeft++) {
                for (int survivorsMid = 0; survivorsMid <= midCount; survivorsMid++) {
                    int pos1 = survivorsLeft + 1;
                    int pos2 = pos1 + survivorsMid + (remainMidCount + 1) / 2 + 1;

                    vector<int> tempResult = earliestAndLatest(nextRoundPlayersCount, pos1, pos2);

                    minRound = min(minRound, tempResult[0] + 1);
                    maxRound = max(maxRound, tempResult[1] + 1);
                }
            }
        }

        return dp[key] = {minRound, maxRound};
    }
};