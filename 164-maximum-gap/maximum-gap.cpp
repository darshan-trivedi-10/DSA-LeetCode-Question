class Solution {
public:
    int maximumGap(vector<int>& nums) {
        const int n = nums.size();
        if (n < 2)
            return 0;

        int maxE = *max_element(nums.begin(), nums.end());
        int minE = *min_element(nums.begin(), nums.end());

        int gap = ceil(static_cast<double>(maxE - minE) / (n - 1));
        if (gap == 0)
            gap = 1;

        int numBuckets = (maxE - minE) / gap + 1;
        vector<pair<int, int>> buckets(numBuckets, {INT_MAX, INT_MIN});

        for (auto i : nums) {
            int bucketIndex = (i - minE) / gap;
            buckets[bucketIndex].first = min(buckets[bucketIndex].first, i);
            buckets[bucketIndex].second = max(buckets[bucketIndex].second, i);
        }

        int prev = minE;
        int maxGap = 0;

        for (auto& bucket : buckets) {
            if (bucket.first == INT_MAX)
                continue;

            maxGap = max(maxGap, bucket.first - prev);
            prev = bucket.second;
        }

        return maxGap;
    }
};
