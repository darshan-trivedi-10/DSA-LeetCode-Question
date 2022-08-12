class Solution {
    void dfs(int node, vector<int> adjList[], vector<bool> &visited){
        visited[node] = true;
        
        for(auto it : adjList[node]){
            if(visited[it]==false){
                dfs(it, adjList, visited);
            }
        }
    }
        
public:
    int findCircleNum(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> adjList[V];
    
        for(int i = 0; i<V; i++){
            for(int j = 0; j<V; j++){
                if(adj[i][j]==1 and i != j){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        
        vector<bool> visited(V, false);
        
        int ans = 0;
        for(int i = 0; i<V; i++){
            if(visited[i]==false){
                ans++;
                dfs(i,adjList, visited);
            }
        }
        
        return ans;
    }
};