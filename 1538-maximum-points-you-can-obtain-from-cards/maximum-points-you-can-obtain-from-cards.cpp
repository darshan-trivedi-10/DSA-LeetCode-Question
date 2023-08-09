class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int size = cardPoints.size();
        vector<int> prefixSum(size, 0);
        for(int i = 0; i < size; i++){
            prefixSum[i] = cardPoints[i];
            if(i > 0){
                prefixSum[i] += prefixSum[i-1];
            }
        }

        for(auto it : prefixSum){
            cout<<it<<" ";
        }cout<<endl;

        int maxPoints = 0;
        for(int i = 0; i <= k; i++){
            int le = i, re = k - i, currPoints = 0;
            if(le > 0){
                currPoints += prefixSum[le - 1];
            }
            if(re > 0){
                cout<<prefixSum[size - 1]<<" "<<prefixSum[size - re]<<" ";
                currPoints += prefixSum[size - 1] - (size-re-1 >= 0 ? prefixSum[size - re-1] : 0);
            }
            cout<<le<<" "<<re<<" "<<currPoints<<endl;
            maxPoints = max(maxPoints, currPoints);
        }

        return maxPoints;
    }
};