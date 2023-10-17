class Solution {
public:
    bool validateBinaryTreeNodes(int n, std::vector<int>& leftChild, std::vector<int>& rightChild) {
        std::vector<int> indegree(n, 0);
        for (int i = 0; i < n; ++i) {
            if (leftChild[i] != -1) indegree[leftChild[i]]++;
            if (rightChild[i] != -1) indegree[rightChild[i]]++;
        }
        int root = -1;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) {
                if (root == -1) root = i;
                else return false;
            }
        }
        if (root == -1) return false;
        std::vector<bool> visited(n, false);
        std::queue<int> queue;
        queue.push(root);
        while (!queue.empty()) {
            int node = queue.front(); queue.pop();
            if (visited[node]) return false;
            visited[node] = true;
            if (leftChild[node] != -1) queue.push(leftChild[node]);
            if (rightChild[node] != -1) queue.push(rightChild[node]);
        }
        return std::accumulate(visited.begin(), visited.end(), 0) == n;
    }
};