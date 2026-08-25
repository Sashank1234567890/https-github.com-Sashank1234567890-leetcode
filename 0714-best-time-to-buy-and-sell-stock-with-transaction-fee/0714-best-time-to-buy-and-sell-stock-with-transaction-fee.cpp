class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {

        int n = prices.size();

        int buy = 0;
        int sell = 0;

        for(int day = n - 1; day >= 0; day--) {

            int newBuy = max(
                sell - prices[day],
                buy
            );

            int newSell = max(
                buy + prices[day] - fee,
                sell
            );

            buy = newBuy;
            sell = newSell;
        }

        return buy;
    }
};