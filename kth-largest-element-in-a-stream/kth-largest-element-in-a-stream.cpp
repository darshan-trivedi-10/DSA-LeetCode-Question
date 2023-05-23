class KthLargest {
    private: 
    int K = 0;
    multiset<int> numbers;
public:
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(int i = 0; i < nums.size(); i++){
            numbers.insert(nums[i]);
        }
    }
    
    int add(int val) {
        numbers.insert(val);
        int KthElement = *next(numbers.begin(), numbers.size() - K);
        return KthElement;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */