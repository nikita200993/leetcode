#include "candy.h"

enum class State {
    Equal,
    Increasing,
    Decreasing,
    Started
};

int candy::Solution::candy(std::vector<int> &ratings) {
    if (ratings.size() == 1) {
        return 1;
    }
    int candies = 1;
    int lastCandiesAmount = 1;
    int sequenceLength = 1;
    int lastPeakValue = -1;
    State state = State::Started;

    for (int i = 1; i < ratings.size(); i++) {
        if (state == State::Started) {
            if (ratings[i] > ratings[i - 1]) {
                lastCandiesAmount++;
                candies += lastCandiesAmount;
                state = State::Increasing;
            } else if (ratings[i] == ratings[i - 1]) {
                lastCandiesAmount = 1;
                candies += lastCandiesAmount;
                state = State::Equal;
            } else {
                candies += sequenceLength;
                candies += 1;
                lastCandiesAmount = 1;
                state = State::Decreasing;
                sequenceLength++;
            }
        } else if (state == State::Increasing) {
            if (ratings[i] > ratings[i - 1]) {
                lastCandiesAmount++;
                candies += lastCandiesAmount;
                sequenceLength++;
            } else if (ratings[i] == ratings[i - 1]) {
                lastCandiesAmount = 1;
                candies += lastCandiesAmount;
                sequenceLength = 1;
                state = State::Equal;
            } else {
                lastPeakValue = lastCandiesAmount;
                state = State::Decreasing;
                lastCandiesAmount = 1;
                candies += lastCandiesAmount;
                sequenceLength = 1;
            }
        } else if (state == State::Decreasing) {
            if (ratings[i] > ratings[i - 1]) {
                state = State::Increasing;
                lastCandiesAmount++;
                candies += lastCandiesAmount;
                sequenceLength = 1;
            } else if (ratings[i] == ratings[i - 1]) {
                state = State::Equal;
                lastCandiesAmount = 1;
                candies += lastCandiesAmount;
            } else {
                lastCandiesAmount = 1;
                candies += sequenceLength;
                sequenceLength++;
                if (lastPeakValue == sequenceLength) {
                    lastPeakValue = -1;
                    sequenceLength++;
                    candies++;
                }
            }
        } else {
            if (ratings[i] > ratings[i - 1]) {
                state = State::Increasing;
                lastCandiesAmount = 2;
                candies += lastCandiesAmount;
            } else if (ratings[i] == ratings[i - 1]) {
                lastCandiesAmount = 1;
                candies += lastCandiesAmount;
            } else {
                state = State::Decreasing;
                sequenceLength = 2;
                lastCandiesAmount = 1;
                candies += sequenceLength;
            }
        }
    }
    return candies;
}