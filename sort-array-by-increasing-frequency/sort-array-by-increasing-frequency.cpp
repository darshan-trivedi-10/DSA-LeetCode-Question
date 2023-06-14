class Compare{
    public : 
    bool operator()(pair<int,int> a, pair<int,int> b){
        if(a.first == b.first){
            return a.second < b.second;
        }

        return a.first > b.first;
    }
};

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mpp;

        for(int i = 0; i < nums.size(); i++){
            mpp[nums[i]]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;
        for(auto it : mpp){
            pq.push({it.second, it.first});
        }
        
        vector<int> sortedArr;
        while(!pq.empty()){
            int totalElement = pq.top().first;
            int element = pq.top().second;
            pq.pop();
            while(totalElement > 0){
                sortedArr.push_back(element);
                totalElement--;
            }
        }

        return sortedArr;
    }
};