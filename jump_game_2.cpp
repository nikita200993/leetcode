#include "jump_game_2.h"

int jump_game_2::Solution::jump(std::vector<int> &nums) {
    if (nums.size() < 2) {
        return 0;
    }
    long last = 0;
    long max = 1;
    int jumps = 0;
    for (long i = 1; i < nums.size(); i++) {
        if (nums[last] + last < i) {
            last = max;
            max = i;
            jumps++;
        } else if (nums[i] + i > nums[max] + max) {
            max = i;
        }
    }
    return jumps + 1;
}
// jump_game_2