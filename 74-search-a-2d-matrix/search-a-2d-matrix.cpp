class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Get the number of rows and columns in the matrix
        const int num_rows = matrix.size();
        const int num_cols = matrix[0].size();
        
        // Initialize start and end for binary search
        int start = 0;
        int end = num_rows * num_cols - 1;
        
        // Perform binary search
        while (start <= end) {
            // Compute middle index and current element
            int mid = (start + end) / 2;
            int currElem = matrix[mid / num_cols][mid % num_cols];
            
            // Check if target is found
            if (currElem == target) {
                return true;
            }
            // Update end for binary search
            else if (currElem > target) {
                end = mid - 1;
            }
            // Update start for binary search
            else {
                start = mid + 1;
            }
        }
        
        // Target not found
        return false;
    }
};
