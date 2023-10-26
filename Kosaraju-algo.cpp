#include <iostream>
#include <vector>
#include <stack>

class Graph {
    int V; // Number of vertices
    std::vector<std::vector<int>> adj; // Adjacency list

public:
    Graph(int vertices) : V(vertices) {
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    // Function to perform DFS starting from a given vertex
    void DFS(int v, std::vector<bool>& visited, std::stack<int>& stack) {
        visited[v] = true;

        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                DFS(neighbor, visited, stack);
            }
        }

        stack.push(v);
    }

    // Function to perform DFS starting from a given vertex and print the SCC
    void DFSUtil(int v, std::vector<bool>& visited) {
        visited[v] = true;
        std::cout << v << " ";

        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }

    // Function to find and print strongly connected components
    void findSCCs() {
        std::stack<int> stack;
        std::vector<bool> visited(V, false);

        // Perform the first pass of DFS to fill the stack
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                DFS(i, visited, stack);
            }
        }

        // Create a transpose of the graph by reversing all edges
        Graph transposedGraph(V);
        for (int i = 0; i < V; ++i) {
            for (int neighbor : adj[i]) {
                transposedGraph.addEdge(neighbor, i);
            }
        }

        visited.assign(V, false); // Reset the visited array

        // Perform the second pass of DFS to find and print SCCs
        while (!stack.empty()) {
            int v = stack.top();
            stack.pop();

            if (!visited[v]) {
                transposedGraph.DFSUtil(v, visited);
                std::cout << std::endl;
            }
        }
    }
};

int main() {
    Graph g(5); // Create a graph with 5 vertices

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(1, 3);
    g.addEdge(3, 4);

    std::cout << "Strongly Connected Components:\n";
    g.findSCCs();

    return 0;
}
