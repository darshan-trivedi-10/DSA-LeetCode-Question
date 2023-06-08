class Solution {
public:
    std::vector<int> nextGreaterElements(const std::vector<int>& nums) {
        const int size = nums.size();
        stack<int> numStack;
        vector<int> greaterElements(size, -1);

        for (int i = 2 * size - 1; i >= 0; i--) {
            int index = i % size;
            while (!numStack.empty() && numStack.top() <= nums[index]) {
                numStack.pop();
            }
            if (!numStack.empty()) {
                greaterElements[index] = numStack.top();
            }
            numStack.push(nums[index]);
        }

        return greaterElements;
    }
};
