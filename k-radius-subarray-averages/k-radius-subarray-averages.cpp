class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int windowSize) {
        const int size = nums.size();
        vector<int> averages(size, -1);

        long long sumFront = 0, sumBack = 0;

        for (int i = 0; i < windowSize; i++) {
            if (i < size) {
                sumBack += nums[i];
            }
        }

        for (int i = 0; i < size; i++) {
            if (i > windowSize) {
                sumFront += nums[i] - nums[i - windowSize - 1];
            } else {
                sumFront += nums[i];
            }

            if (i + windowSize < size) {
                sumBack = sumBack - nums[i] + nums[i + windowSize];
            }

            if (i >= windowSize && i + windowSize < size) {
                averages[i] = (sumFront + sumBack) / (2 * windowSize + 1);
            }
        }

        return averages;
    }
};
