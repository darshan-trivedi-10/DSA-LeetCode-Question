class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> lis;
        vector<int> lisLen(obstacles.size());
        for(int i=0;i<obstacles.size();i++){
            int val = obstacles[i];
            if(lis.size()==0 || lis.back() <= val){
                lis.push_back(val);
                lisLen[i] = lis.size();
            }else{
                int idx = upper_bound(lis.begin(), lis.end(), val) - lis.begin();
                lis[idx] = val;
                lisLen[i] = idx + 1;
            }
        }
        return lisLen;
    }
};