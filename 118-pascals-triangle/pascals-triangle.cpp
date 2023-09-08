class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangles(numRows);

        for(int i = 0; i < numRows; i++){
            triangles[i].resize(i + 1, 0);
            for(int j = 0; j <= i; j++){
                if(j == 0 || j == i){
                    triangles[i][j] = 1;
                }else{
                    triangles[i][j] += triangles[i-1][j] + triangles[i-1][j-1];
                }
            }
        }

        return triangles;
    }
};