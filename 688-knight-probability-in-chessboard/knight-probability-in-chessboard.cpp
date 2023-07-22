class Solution {

    bool isValid(int n, int row, int col){
        return ((row <= n && col <= n && row > 0 && col > 0));
    }
    
    
    int dir[8][8] = {{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1}};
    unordered_map<string, double> dp;

    double count(int n, int row, int col, int k){
        if(!isValid(n, row, col)){
            return 0;
        }

        if(k == 0){
            return 1;
        }

        string key = to_string(row) + "_" + to_string(col) + ":" + to_string(k);
        if(dp.find(key) != dp.end()){
            return dp[key];
        }


        double totalPossibility = 0;

        for(int i = 0; i < 8; i++){
            totalPossibility += count(n, row + dir[i][0], col + dir[i][1], k - 1);
        }

        return dp[key] = totalPossibility/8.0;
    }

public:
    double knightProbability(int n, int k, int row, int column) {
        if(k == 0){
            return 1;
        }
        return count(n, row + 1, column + 1, k);
    }
};