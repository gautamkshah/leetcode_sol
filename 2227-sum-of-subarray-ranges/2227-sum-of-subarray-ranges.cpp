
class MonoStack {
public:
    deque<int> deque;
    vector<int> left, right, data;
    int size;
    bool isIncreasing;

    MonoStack(int n, vector<int>& data, bool isIncreasing) : size(n), data(data), isIncreasing(isIncreasing) {
        left.resize(n, -1);
        right.resize(n, n);
    }

    bool canPush(int index) {
        return isIncreasing ? (data[deque.back()] < data[index]) : (data[deque.back()] > data[index]);
    }

    void push(int index) {
        while (!deque.empty() && !canPush(index)) {
            int topIndex = deque.back();
            deque.pop_back();
            right[topIndex] = index;
        }
        if (!deque.empty()) {
            left[index] = deque.back();
        }
        deque.push_back(index);
    }

    int leftCount(int index) {
        return index - (left[index] + 1);
    }

    int rightCount(int index) {
        return right[index] - (index + 1);
    }
};

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        MonoStack increasing(nums.size(), nums, true);
        MonoStack decreasing(nums.size(), nums, false);

        for (int i = 0; i < nums.size(); ++i) {
            increasing.push(i);
            decreasing.push(i);
        }

        long long total = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int minLeft = increasing.leftCount(i);
            int minRight = increasing.rightCount(i);

            int maxLeft = decreasing.leftCount(i);
            int maxRight = decreasing.rightCount(i);

            long long totalMinFor = minLeft + minRight + (long long)(minLeft * minRight);
            long long totalMaxFor = maxLeft + maxRight + (long long)(maxLeft * maxRight);

            total += (long long)(nums[i]) * totalMaxFor;
            total -= (long long)(nums[i]) * totalMinFor;
        }
        return total;
    }
};
