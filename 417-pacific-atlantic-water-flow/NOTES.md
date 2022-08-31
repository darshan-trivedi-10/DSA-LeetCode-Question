if(heights[nx][ny]>=heights[i][j]){
isContain[nx][ny] = true;
Helper(heights, isContain, nx, ny);
}
}
}
}
}
public:
vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
int n = heights.size(), m = heights[0].size();
vector<vector<bool>> isContain(n, vector<bool> (m,false));
isContain[0][m-1] = true;
Helper(heights, isContain, 0, m-1);
isContain[n-1][0] = true;
Helper(heights, isContain, n-1, 0);
​
vector<vector<int>> ans;
for(int i = 0; i<n; i++){
for(int j = 0; j<m; j++){
cout<<isContain[i][j]<<" ";
if(isContain[i][j]==true){
ans.push_back({i,j});
}
}cout<<endl;
}
return ans;
}
};