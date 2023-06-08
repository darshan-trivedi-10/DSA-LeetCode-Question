class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        const int n = grid.size(), m = grid[0].size();
        int negetives = 0;

        int i = n - 1, j = 0;
        while(i >= 0 && j < m){
            if(grid[i][j] < 0){
                negetives += m - j;
                i--;
            }else{
                j++;
            }
        }

        return negetives;
    }
};