#include <iostream>
#include <vector>
#include <stack>
#include <deque>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

void dfs1(int v, const vector<deque<int>>& graph, vector<bool>& visited, deque<int>& finishOrder) {
    visited[v] = true;
    for (int u : graph[v]) {
        if (!visited[u]) {
            dfs1(u, graph, visited, finishOrder);
        }
    }
    finishOrder.push_back(v);
}

void dfs2(int v, const vector<deque<int>>& reverseGraph, vector<bool>& visited, vector<int>& component) {
    visited[v] = true;
    component.push_back(v);
    for (int u : reverseGraph[v]) {
        if (!visited[u]) {
            dfs2(u, reverseGraph, visited, component);
        }
    }
}

int main() {
    int n, m;
    cout << "enter the number of vertexs in the graph" << endl;
    cin >> n;
    cout << "enter the number of edges in the graph" << endl;
    cin >> m;

    vector<deque<int>> graph(n + 1);
    vector<deque<int>> reverseGraph(n + 1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cout << "enter the " << i + 1 << " edge" << endl;
        cin >> u >> v;
        graph[u].push_back(v);
        reverseGraph[v].push_back(u);
    }

    vector<bool> visited(n + 1, false);
    deque<int> finishOrder;
    
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            dfs1(i, graph, visited, finishOrder);
        }
    }

    fill(visited.begin(), visited.end(), false);
    vector<vector<int>> stronglyConnectedComponents;

    while (!finishOrder.empty()) {
        int v = finishOrder.front();
        finishOrder.pop_front();
        if (!visited[v]) {
            vector<int> component;
            dfs2(v, reverseGraph, visited, component);
            stronglyConnectedComponents.push_back(component);
        }
    }

    cout << "strongly connected component : " << endl; 
    for (const auto& component : stronglyConnectedComponents) {
        for (int v : component) {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}
