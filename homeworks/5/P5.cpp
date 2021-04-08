//#include <iostream>
//
//using namespace std;
//
//int main() {
//    int n, from, to;
//    cin >> n;
//    int matrix[n][n], next[n][n];
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            cin >> matrix[i][j];
//        }
//    }
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            next[i][j] = 0;
//        }
//    }
//    cin >> from >> to;
//    for (int i = 0; i < n; i++) {
//        for (int u = 0; u < n; u++) {
//            for (int v = 0; v < n; v++) {
//                if (matrix[u][i] + matrix[i][v] < matrix[u][v] && matrix[u][i] != 0 && matrix[i][v] != 0) {
//                    matrix[u][v] = matrix[u][i] + matrix[i][v];
//                    next[u][v] = next[u][i];
//                }
//            }
//        }
//    }
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            cout << matrix[i][j] << (j + 1 == n ? '\n' : ' ');
//        }
//    }
//    if (matrix[from][to] == 0) {
//        cout << -1;
//    } else {
//        while (from != to) {
//            cout << from << " ";
//            from = next[from][to];
//        }
//        cout << to;
//    }
//    return 0;
//}
#include <iostream>
#include <vector>

using namespace std;

struct adjacency_vertex {
    int vertex;
    int weight;
};

int main() {
    const int temp = 2147483647;
    int n;
    cin >> n;
    vector<vector<adjacency_vertex >> adjacency_list;
    for (int i = 0; i < n; i++) {
        int mi;
        cin >> mi;
        vector<adjacency_vertex> adjacent_vertices;
        adjacency_list.push_back(adjacent_vertices);
        for (int j = 0; j < mi; j++) {
            adjacency_vertex adj;
            cin >> adj.vertex >> adj.weight;
            adj.vertex--;
            adjacency_list[i].push_back(adj);
        }
    }
    int s, t;
    cin >> s >> t;
    s--;
    t--;
    vector<int> d(n, temp);
    d[s] = 0;
    vector<bool> u(n, false);
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!u[j] && (v == -1 || d[j] < d[v])) {
                v = j;
            }
        }
        if (d[v] == temp) {
            break;
        }
        u[v] = true;
        for (int j = 0; j < adjacency_list[v].size(); j++) {
            int vertex = adjacency_list[v][j].vertex;
            int weight = adjacency_list[v][j].weight;
            if (d[v] + weight < d[vertex]) {
                d[vertex] = d[v] + weight;
                p[vertex] = v;
            }
        }
    }
    vector<int> path;
    for (int v = t; v != s; v = p[v]) {
        path.push_back(v);
    }
    path.push_back(s);
    if (d[t] == temp) {
        cout << -1;
    }
    else {
        cout << d[t] << endl;
        cout << path.size() - 1 << endl;
        for (int i = path.size() - 1; i >= 0; i--) {
            cout << path[i] + 1 << " ";
        }
    }
    return 0;
}