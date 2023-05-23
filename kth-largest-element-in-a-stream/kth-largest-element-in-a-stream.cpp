class KthLargest {
private:
    int K;
    std::multiset<int> numbers;

public:
    KthLargest(int k, const std::vector<int>& nums)  {
        K = k;
        for(int ele : nums){
            numbers.insert(ele);
        }
    }

    int add(int val) {
        numbers.insert(val);
        auto kthElementIter = std::next(numbers.begin(), numbers.size() - K);
        return *kthElementIter;
    }
};