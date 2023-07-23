#include "jump_game.h"

bool jump_game::Solution::canJump(std::vector<int>& nums) {
    if (nums.size() < 2) {
        return true;
    }
    auto last = nums.size() - 1;
    for (long i = nums.size() - 2; i >= 0; i--) {
        if (i + nums[i] >= last) {
            last = i;
        }
    }
    return last == 0;
}