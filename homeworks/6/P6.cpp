#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int mass[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mass[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++) {
        int x, y, v;
        cin >> x >> y >> v;
        mass[x-1][y-1] = v;
        mass[y-1][x-1] = v;
    }
    bool ans = true;
    for (int i = 0; i < n; i++) {
        int check = 0;
        for (int j = 0; j < n; j++) {
            if (mass[i][j] == 0) {
                check++;
            } else {
                break;
            }
        }
        if (check == n) {
            cout << "-1";
            ans = false;
        }
    }
    if (ans) {
        bool *visited = new bool[n];
        memset(visited, false, sizeof(bool) * n);
        visited[0] = true;
        int answer = 0;
        for (int l = 0; l < n - 1; l++) {
            int minx = -1, miny = -1;
            for (int i = 0; i < n; i++)
                if (visited[i])
                    for (int j = 0; j < n; j++)
                        if (!visited[j] && mass[i][j] > 0 && (miny == -1 || mass[i][j] < mass[miny][minx]))
                            miny = i, minx = j;
            visited[minx] = true;
            answer += mass[miny][minx];
        }

        cout << answer;
    }

    return 0;
}