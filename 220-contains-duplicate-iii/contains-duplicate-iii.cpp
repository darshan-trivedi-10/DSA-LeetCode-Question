class Solution {

    bool isPossible(vector<int> &bucket, int valueDiff){
        int i = 0, j = 1, n = bucket.size();
        while(i < n && j < n){
            int diff = bucket[j] - bucket[i];
            if(diff <= valueDiff){
                return true;
            }else{
                i++;
                if(i == j){
                    j++;
                }
            }
        }

        return false;
    }

    void arrangeArray(vector<int> &bucket, int remove, int add){
        // [1, 2, 2, 3, 4, 5], remove 2 add three
        int i = 0, n = bucket.size();
        while(i < n){
            if(bucket[i] == remove){
                break;
            }
            i++;
        }

        bucket[i] = add;
        while(i > 0 && bucket[i] < bucket[i-1]){
            swap(bucket[i], bucket[i-1]);
            i--;
        }

        while(i < n - 1 && bucket[i] > bucket[i+1]){
            swap(bucket[i], bucket[i+1]);
            i++;
        }
    }

public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {

        const int size = nums.size();
        vector<int> bucket;
        for(int i = 0; i <= min(indexDiff, size - 1); i++){
            bucket.push_back(nums[i]);
        }

        sort(bucket.begin(), bucket.end());
        if(isPossible(bucket, valueDiff)){
            return true;
        }
        int i = indexDiff, start = 0;
        while(i < size){
            if(isPossible(bucket, valueDiff)){
                return true;
            }
            if(i + 1 < size){
                int nextElement = nums[i + 1];
                arrangeArray(bucket, nums[start], nextElement);
            }
            start++, i++;
        }
        
        return false;
    }
};