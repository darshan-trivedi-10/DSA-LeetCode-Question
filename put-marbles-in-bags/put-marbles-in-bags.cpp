class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        const int size = weights.size();

        vector<int> sum;
        for(int i = 0; i < size-1; i++){
            sum.push_back(weights[i] + weights[i + 1]);
        }

        sort(sum.begin(), sum.end());

        long maxScore = 0, minScore = 0;
        for(int i = 0; i < k-1; i++){
            minScore += sum[i];
            maxScore += sum[size - i - 2];
        }

        return maxScore - minScore;
    }
};