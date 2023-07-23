#include "best_time_to_buy_sell_stock.h"

int best_time_to_buy_sell_stock::Solution::maxProfit(std::vector<int> &prices) {
    if (prices.empty()) {
        return 0;
    }
    int min = prices[0];
    int profit = 0;
    for (int i = 1; i < prices.size(); i++) {
        int value = prices[i];
        int diff = value - min;
        if (value < min) {
            min = value;
        } else if (diff > profit) {
            profit = diff;
        }
    }
    return profit;
}