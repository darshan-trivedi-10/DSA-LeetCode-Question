class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0, sum = gain[0];
        for(int i = 1; i < gain.size(); i++){
            ans = max(ans, sum);
            sum += gain[i];
        }
        
        ans = max(ans, sum);

        return ans;
    }
};