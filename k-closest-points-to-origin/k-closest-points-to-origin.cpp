class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        const int n = points.size();
        priority_queue<pair<long,vector<int>>> pq;
        vector<vector<int>> closestPoints;
        for(int i = 0; i < n; i++){
            int x = points[i][0], y = points[i][1];
            long distance = (((x * x) + (y * y)));
            pq.push({distance, points[i]});
            if(pq.size() > k){
                cout<<pq.top().first<<endl;
                pq.pop();
            }
        }

        while(!pq.empty()){
            cout<<pq.top().first<<endl;
            closestPoints.push_back(pq.top().second);
            pq.pop();
        }

        // 25 + 16 = 41 = 6
        // 36 + 25 = 61 = 7
        // 16 + 36 = 52 = 7


        return closestPoints;
    }
};