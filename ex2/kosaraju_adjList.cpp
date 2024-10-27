#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <algorithm>

using namespace std;

void dfs1(int v, const vector<deque<int>>& graph, vector<bool>& visited, stack<int>& finishStack) {
    visited[v] = true;
    for (int u : graph[v]) {
        if (!visited[u]) {
            dfs1(u, graph, visited, finishStack);
        }
    }
    finishStack.push(v);
}

void dfs2(int v, const vector<deque<int>>& reverseGraph, vector<bool>& visited, deque<int>& component) {
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

    stack<int> finishStack;
    vector<bool> visited(n + 1, false);

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            dfs1(i, graph, visited, finishStack);
        }
    }

    fill(visited.begin(), visited.end(), false);
    vector<deque<int>> stronglyConnectedComponents;

    while (!finishStack.empty()) {
        int v = finishStack.top();
        finishStack.pop();
        if (!visited[v]) {
            deque<int> component;
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