class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        const int size = heights.size();
        
        vector<int> leftSmaller(size, 0), rightSmaller(size, size - 1);
        stack<int> st;
        for(int i = 0; i < size; i++){
            if(!st.empty()){
                while(!st.empty()){
                    if(heights[st.top()] < heights[i]){
                        leftSmaller[i] = st.top() + 1;
                        break; 
                    }
                    st.pop();
                }
            }

            st.push(i);
        }

        while (!st.empty()) {
            st.pop();
        }

        for(int i = size-1; i >= 0; i--){
            if(!st.empty()){
                while(!st.empty()){
                    if(heights[st.top()] < heights[i]){
                        rightSmaller[i] = st.top() - 1;
                        break;
                    }
                    st.pop();
                }
            }
            st.push(i);
        }

        int maxHistrogram = 0;
        for(int i = 0; i < size; i++){
            int area = heights[i] * (rightSmaller[i] - leftSmaller[i] + 1);
            maxHistrogram = max(maxHistrogram, area);
        }

        return maxHistrogram;



    }
};