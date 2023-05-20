class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int ans=0,n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){ //loop for checking the first element in row is 1 or not
            if(grid[i][0]!=1){ 
                for(int j=0;j<m;j++){
                    if(grid[i][j]==0){
                        grid[i][j]=1;
                    }
                    else{
                        grid[i][j]=0;
                    }
                }
            }
        }
        for(int i=0;i<m;i++){ // Loop for traversing the column to check the number of 1 in column is greater than half the number of rows or not.
            int x=0;
            for(int j=0;j<n;j++){
                if(grid[j][i]==1){
                    x++;
                }
            }
            if(x<ceil(n/2.0)){
                for(int j=0;j<n;j++){
                    if(grid[j][i]==1){
                        grid[j][i]=0;
                    }
                    else{
                        grid[j][i]=1;
                    }
                }
            }
        }
        for(auto x:grid){ // Loop for converting the grid into decimal.
            int z=0,f=m-1;
            for(auto y:x){
                z+=pow(2,f)*y;
                f--;
            }
            ans+=z;
        }
        return ans;
    }
};