#include <iostream>

using namespace std;

int main() {
    int n, s;
    cin >> n >> s;
    int f[n + 1][s + 1];
    int c[n];
    int ans[n];
    int t = n;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        ans[i] = 0;
    }
    f[0][0] = 0;
    for (int i = 1; i < s + 1; i++) {
        f[0][i] = 10000;
    }

    int min;
    for (int i = 1; i < n + 1; i++) {
        for (int j = 0; j < s + 1; j++) {
            min = 10000;
            if (c[i - 1] <= j) {
                min = f[i][j - c[i - 1]] + 1;
            }
            if (f[i - 1][j] != -1) {
                if (f[i - 1][j] < min) {
                    min = f[i - 1][j];
                }
            }
            if (min != 10000) {
                f[i][j] = min;
            } else {
                f[i][j] = 10000;
            }
        }
    }

    if (f[n][s] != 10000) {
        cout << f[n][s] << endl;
        while (f[n][s] != 0) {
            if (c[n - 1] <= s) {
                if (f[n][s - c[n - 1]] + 1 == f[n][s]) {
                    ans[n - 1]++;
                    s = s - c[n - 1];
                    continue;
                }
            }
            n--;
        }
        for (int k = 0; k < t; k++) {
            cout << ans[k] << " ";
        }
    } else {
        cout << -1;
    }

    return 0;
}
