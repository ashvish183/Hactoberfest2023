#include <iostream>
#include <vector>
#include <stack>

class Graph {
    int V; // Number of vertices
    std::vector<std::vector<int>> adj; // Adjacency list
    int id; // Counter for assigning unique ids to vertices
    std::vector<int> lowlink; // Lowlink values for vertices
    std::vector<int> ids; // Ids of vertices
    std::vector<bool> onStack; // Tracks whether a vertex is on the stack
    std::stack<int> stack; // Stack to hold vertices in the current SCC
    int SCCCount; // Counter for counting SCCs

public:
    Graph(int vertices) : V(vertices), id(0), SCCCount(0) {
        adj.resize(V);
        lowlink.resize(V, -1);
        ids.resize(V, -1);
        onStack.resize(V, false);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    // Function to perform DFS starting from a given vertex
    void DFS(int v) {
        stack.push(v);
        onStack[v] = true;
        ids[v] = lowlink[v] = id++;

        for (int neighbor : adj[v]) {
            if (ids[neighbor] == -1) {
                DFS(neighbor);
            }
            if (onStack[neighbor]) {
                lowlink[v] = std::min(lowlink[v], lowlink[neighbor]);
            }
        }

        if (ids[v] == lowlink[v]) {
            while (stack.top() != v) {
                int w = stack.top();
                stack.pop();
                onStack[w] = false;
                std::cout << w << " ";
            }
            int w = stack.top();
            stack.pop();
            onStack[w] = false;
            std::cout << w << "\n";
            SCCCount++;
        }
    }

    // Function to find and print strongly connected components
    void findSCCs() {
        for (int i = 0; i < V; ++i) {
            if (ids[i] == -1) {
                DFS(i);
            }
        }
    }
};

int main() {
    Graph g(8); // Create a graph with 8 vertices

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 3);
    g.addEdge(6, 5);
    g.addEdge(6, 7);

    std::cout << "Strongly Connected Components:\n";
    g.findSCCs();

    return 0;
}
