#include<bits/stdc++.h>
using namespace std;

bool cycleDetectUsingDFS(vector<int>adj[], int source, int parent, vector<int>&vis)
{
    vis[source] = 1;  // marking the source node as visited
    for(auto adjNode : adj[source])
    {
        if(vis[adjNode] == 0)  
        {
            // If adjNode is not visited then make a recursive call. In the recursive call source node will become parent node and adjNode will become child node or source node
            if(cycleDetectUsingDFS(adj, adjNode, source, vis))
                return true;   
        }
        else if(adjNode != parent) 
        {
            // If adjNode is already visited and it is not the parent node, then we have must visited it before by some other path. Hence, it will contain cycle.
            return true;
        }
    }
    return false;
}

int main()
{
    int number_of_vertex; // number of vertex
    cin >> number_of_vertex;

    int nubmer_of_edge;
    cin >> nubmer_of_edge; // number of edges

    vector<int>adj[number_of_vertex];  // adjacecny list
    // Here we are taking 0-based indexing

    for(int i = 0; i < nubmer_of_edge; i++)
    {
        int node1, node2;
        cin >> node1 >> node2;
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }

    vector<int>vis(number_of_vertex, 0);

    bool flag = false;

    for(int i =  0; i < number_of_vertex; i++)
    {
        if(vis[i] == 0)
        {
            if(cycleDetectUsingDFS(adj,i,-1,vis))
            {
                cout << "The graph contain a cycle" << '\n';
                flag = true;
                break;
            }
        }
    }

    if(!flag)
    {
        cout << "The graph does not contain a cyle" << '\n';
    }

    return 0;
}
