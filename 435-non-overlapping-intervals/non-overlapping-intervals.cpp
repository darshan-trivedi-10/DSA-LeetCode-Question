class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
            if(a[0] == b[0]){
                return a[0] < b[0];
            }
            return a[0] < b[0];
        });

        int start = INT_MIN, end = INT_MIN;
        int totalIntervals = 0;

        for(int i = 0; i < intervals.size(); i++){
            // [1, 10], [2, 3], [3, 4], [4,7]
            int currStart = intervals[i][0], currEnd = intervals[i][1];
            if(start == INT_MIN || currStart >= end){
                start = currStart, end = currEnd;
            }else{
                if(end > currEnd){
                    totalIntervals++;
                    start = currStart, end = currEnd;
                }else{
                    totalIntervals++;
                }
            }
        }
        
        return totalIntervals;
    }
};