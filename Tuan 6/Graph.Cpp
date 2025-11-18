#include <iostream>
#include <vector>
#include <queue>

using namespace std;


void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}


void dfs(int u, vector<bool>& visited, const vector<vector<int>>& adj) {
    visited[u] = true;
    cout << u << " "; 

    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, visited, adj);
        }
    }
}


void bfs(int s, vector<bool>& visited, const vector<vector<int>>& adj) {
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " "; 

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}


int main() {
    int V = 7; 
    vector<vector<int>> adj(V);

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 5);
    

    cout << "Duyet theo DFS (bat dau tu 0):" << endl;
    vector<bool> visited_dfs(V, false);
    
    for (int i = 0; i < V; ++i) {
        if (!visited_dfs[i]) {
            dfs(i, visited_dfs, adj);
        }
    }
    cout << "\n--------------------------" << endl;


    cout << "Duyet theo BFS (bat dau tu 0):" << endl;
    vector<bool> visited_bfs(V, false);

    for (int i = 0; i < V; ++i) {
        if (!visited_bfs[i]) {
            bfs(i, visited_bfs, adj);
        }
    }
    cout << "\n--------------------------" << endl;

    return 0;
}