#include "best_time_to_buy_sell_stock_2.h"

int best_time_to_buy_sell_stock_2::Solution::maxProfit(std::vector<int> &prices) {
    if (prices.empty()) {
        return 0;
    }
    int profit = 0;
    for (int i = 1; i < prices.size(); i++) {
        int delta = prices[i] - prices[i - 1];
        if (delta > 0) {
            profit += delta;
        }
    }
    return profit;
}