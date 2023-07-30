#include "gas_station.h"

#include <vector>

int gas_station::Solution::canCompleteCircuit(std::vector<int> &gas, std::vector<int> &cost) {
    int tank = 0;
    int min = 0;
    int index = 0;
    for (int i = 0; i < gas.size(); i++) {
        tank += gas[i] - cost[i];
        if (tank < min) {
            min = tank;
            index = i;
        }
    }
    if (tank < 0) {
        return -1;
    } else if (min >= 0) {
        return 0;
    } else {
        return (index + 1) % gas.size();
    }
}