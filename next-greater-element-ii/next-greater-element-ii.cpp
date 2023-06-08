class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        const int size = nums.size();
        stack<int> st;
        vector<int> greaterElement(size, -1); 
        for(int i =  2 * size - 1; i >=0; i--){
            int idx = i%size;
            if(!st.empty()){
                if(st.top() > nums[idx]){
                    greaterElement[idx] = st.top();
                }else{
                    while(!st.empty()){
                        if(st.top() > nums[idx]){
                            greaterElement[idx] = st.top();
                            break;
                        }
                        st.pop();
                    }
                }
            }
            st.push(nums[idx]);
        }

        return greaterElement;
    }
};