#include<vector>
#include<iostream>

using namespace std;

void dfs(int v) {
    used[v] = true;
    components.back().push_back(v);
    for (int u : graph[v]) {
        if (!used[u]) {
            dfs(u);
        }
    }
}

int main() {
    int n;
    cin >> n;
    int graph[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    bool used[n];
}