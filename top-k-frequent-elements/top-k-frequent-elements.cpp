class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;

        for(int i = 0; i < nums.size(); i++){
            mpp[nums[i]]++;
        }

        priority_queue<pair<int,int>> pq;
        vector<int> topFreqElements;
        for(auto it : mpp){
            pq.push({it.second, it.first});
            if(pq.size() > (int(mpp.size() - k))){
                topFreqElements.push_back(pq.top().second);
                pq.pop();
            }
        }

        return topFreqElements;
    }
};