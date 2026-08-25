class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {

        int n = prices.size();

        int t[50001][2];

        t[n][0] = 0;
        t[n][1] = 0;

        for(int day = n - 1; day >= 0; day--) {

            // buy
            int consider = t[day + 1][0] - prices[day];
            int not_consider = t[day + 1][1];

            t[day][1] = max(consider, not_consider);

            // sell
            consider = t[day + 1][1] + prices[day] - fee;
            not_consider = t[day + 1][0];

            t[day][0] = max(consider, not_consider);
        }

        return t[0][1];
    }
};