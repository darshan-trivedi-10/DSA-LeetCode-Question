class Solution {

    bool isValid(vector<vector<int>> &matrix, int row, int col){
        int n = matrix.size(), m = matrix[0].size();
        return (min(row, col) >= 0 && row < n && col < m);
    }

    int cherryPicker(vector<vector<int>> &grid, vector<vector<vector<int>>> &dp, int row, int col1, int col2){
        if (! (isValid(grid, row, col1) && isValid(grid, row, col2)) ){
            return 0;
        }

        if(dp[row][col1][col2] != -1){
            return dp[row][col1][col2];
        }

        int cherry = 0;
        if(col1 != col2){
            cherry += grid[row][col1] + grid[row][col2];
        }else{
            cherry += grid[row][col2];
        }

        int rb1[] = {-1, 0, 1};
        int rb2[] = {-1, 0, 1};

        int maxCherry = 0;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                int newCol1 = col1 + rb1[i];
                int newCol2 = col2 + rb2[j];
                maxCherry = max(maxCherry, cherryPicker(grid, dp, row + 1, newCol1, newCol2 ));
            }
        }

        cherry += maxCherry;
        return dp[row][col1][col2] = cherry;
    }

public:
    int cherryPickup(vector<vector<int>>& grid) { 
        int n = grid.size(), m = grid[0].size(); 
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return cherryPicker(grid, dp, 0, 0, m - 1);        
    } 
};