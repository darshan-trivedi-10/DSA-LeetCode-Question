class Solution {
public:
    int trap(vector<int>& height) {
        const int size = height.size();

        int left = 0, right = size - 1;
        int leftMax = 0, rightMax = 0;

        int maxWater = 0;
        while(left <= right){
            if(height[left] <= height[right]){
                if(leftMax < height[left]){
                    leftMax = height[left];
                }else{
                    maxWater += leftMax - height[left];
                    left++;
                }
            }else{
                if(rightMax < height[right]){
                    rightMax = height[right];
                }else{
                    maxWater += rightMax - height[right];
                    right--;
                }
            }
        }        

        return maxWater;
    }
};