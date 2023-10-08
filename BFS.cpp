void BFS(vector<vector<int>>& graph, int source) {  
    vector<bool> visited(graph.size(), false);  
    queue<int> q;  
  
    visited[source] = true;  
    q.push(source);  
  
    while (!q.empty()) {  
        int node = q.front();  
        q.pop();  
        cout << node << " ";  
  
        for (int i = 0; i < graph[node].size(); i++) {  
            int neighbor = graph[node][i];  
            if (!visited[neighbor]) {  
                visited[neighbor] = true;  
                q.push(neighbor);  
            }  
        }  
    }  
}  