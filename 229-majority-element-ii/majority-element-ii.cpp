class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // count the freq of each and every element then do it
        // sort the array and then find it
        const int n = nums.size();
        int ele1, ele2;
        int cnt1 = 0, cnt2 = 0;

        for(auto it : nums){
            if(it == ele1){
                cnt1++;
            }else if(it == ele2){
                cnt2++;
            }else if(cnt1 == 0){
                cnt1++;
                ele1 = it;
            }else if(cnt2 == 0){
                cnt2++;
                ele2 = it;
            }else{
                cnt1--, cnt2--;
            }
        }

        vector<int> majorityEle;
        cnt1 = 0, cnt2 = 0;
        for(auto it : nums){
            if(it == ele1){
                cnt1++;
            }else if(it == ele2){
                cnt2++;
            }
        }

        if(cnt1 > (n/3)){
            majorityEle.push_back(ele1);
        }

        if(cnt2 > (n/3)){
            majorityEle.push_back(ele2);
        }

        return majorityEle;
    }
};