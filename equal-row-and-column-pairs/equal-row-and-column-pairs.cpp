class Solution {
    // iterate through each & every row 
    // i = 0, row[0] = 3  
    // i will go to each & every column where col[0] == row[0
    // untill the last element is same, 
    // if the last element index is n-1 
    // then i will add this row & col in the ans;

public:
    int equalPairs(vector<vector<int>>& grid) {
        const int n = grid.size();

        int totalPairs = 0;
        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                int idx;
                if(grid[row][0] == grid[0][col]){
                    for(idx = 0; idx < n; idx++){
                        if(grid[row][idx] != grid[idx][col]){
                            break;
                        }
                    }
                    if(idx == n){
                        totalPairs++;
                    }
                }
            }
        }

        return totalPairs;
    }
};