#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Graph {
private:
    int rows, cols;
    vector<vector<int>> graph;
    vector<vector<int>> reverseGraph;

public:
    Graph(int n, int m) : rows(n), cols(m), graph(n + 1), reverseGraph(n + 1) {}

    vector<vector<int>>& getGraph() {
        return graph;
    }

    vector<vector<int>>& getReverseGraph() {
        return reverseGraph;
    }

    // Function to add a new edge from u to v
    void addEdge(int u, int v) {
        graph[u].push_back(v);
        reverseGraph[v].push_back(u);
    }

    // Function to remove an edge from u to v
    void removeEdge(int u, int v) {
        auto& adjU = graph[u];
        auto& adjV = reverseGraph[v];

        // Remove v from u's adjacency list
        adjU.erase(remove(adjU.begin(), adjU.end(), v), adjU.end());

        // Remove u from v's reverse adjacency list
        adjV.erase(remove(adjV.begin(), adjV.end(), u), adjV.end());
    }
};

class Kosaraju {
private:
    int vertex, edges;
    Graph g;
    stack<int> finishStack;
    vector<bool> visited;

public:
    Kosaraju(int vertex, int edges) : vertex(vertex), edges(edges), g(vertex, edges) {
        this->visited = vector<bool>(this->vertex + 1, false);  // 1-based indexing
    }

    void newEdge(int u, int v) {
        g.addEdge(u, v);
        cout << "Edge (" << u << ", " << v << ") added." << endl;
    }

    void removeEdge(int u, int v) {
        g.removeEdge(u, v);
        cout << "Edge (" << u << ", " << v << ") removed." << endl;
    }

    void dfs1(int v, const vector<vector<int>>& graph, vector<bool>& visited, stack<int>& finishStack) {
        visited[v] = true;
        for (int u : graph[v]) {
            if (!visited[u]) {
                dfs1(u, graph, visited, finishStack);
            }
        }
        finishStack.push(v);
    }

    void dfs2(int v, const vector<vector<int>>& reverseGraph, vector<bool>& visited, vector<int>& component) {
        visited[v] = true;
        component.push_back(v);
        for (int u : reverseGraph[v]) {
            if (!visited[u]) {
                dfs2(u, reverseGraph, visited, component);
            }
        }
    }

    void stronglyConnectedComponents() {
        for (int i = 1; i <= this->vertex; ++i) {
            if (!visited[i]) {
                dfs1(i, this->g.getGraph(), visited, finishStack);
            }
        }

        fill(visited.begin(), visited.end(), false);
        vector<vector<int>> stronglyConnectedComponents;

        while (!finishStack.empty()) {
            int v = finishStack.top();
            finishStack.pop();
            if (!visited[v]) {
                vector<int> component;
                dfs2(v, this->g.getReverseGraph(), visited, component);
                stronglyConnectedComponents.push_back(component);
            }
        }

        cout << "Strongly connected components:" << endl;
        for (const auto& component : stronglyConnectedComponents) {
            for (int v : component) {
                cout << v << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int vertex, edges;
    cout << "Enter the number of vertices in the graph" << endl;
    cin >> vertex;
    cout << "Enter the number of edges in the graph" << endl;
    cin >> edges;

    Kosaraju kosaraju(vertex, edges);
  

    while (true) {
        cout << "Enter command (newEdge u v, removeEdge u v, or exit): ";
        string command;
        cin >> command;

        if (command == "newEdge") {
            int u, v;
            cin >> u >> v;
            kosaraju.newEdge(u, v);
        } else if (command == "removeEdge") {
            int u, v;
            cin >> u >> v;
            kosaraju.removeEdge(u, v);
        } else if (command == "exit") {
            break;
        } else {
            cout << "Unknown command." << endl;
        }
    }

    kosaraju.stronglyConnectedComponents();

    return 0;
}