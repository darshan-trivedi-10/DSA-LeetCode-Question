class Solution {
public:
    int maxArea(vector<int>& height) {
        const int size = height.size();
        int left = 0, right = size - 1;
        int ans = 0;
        while(left < right){
            int currAns = (right - left) * min(height[right], height[left]);
            ans = max(ans, currAns);
            if(height[left] < height[right]){
                left++;
            }else{
                right--;
            }
        }

        return ans;
    }
};