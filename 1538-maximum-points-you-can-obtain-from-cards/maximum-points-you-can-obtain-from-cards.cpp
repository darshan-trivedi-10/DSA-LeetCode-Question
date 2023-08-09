class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int size = cardPoints.size();
        vector<int> prefixSum(size + 1, 0);  // Include an extra element for easier calculations
        
        for (int i = 0; i < size; i++) {
            prefixSum[i + 1] = prefixSum[i] + cardPoints[i];  // Build prefix sum array
        }

        int maxPoints = 0;
        for (int i = 0; i <= k; i++) {
            int le = i, re = k - i, currPoints = 0;
            currPoints = prefixSum[le] + (prefixSum[size] - prefixSum[size - re]);

            maxPoints = max(maxPoints, currPoints);
        }

        return maxPoints;
    }
};
