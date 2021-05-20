#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

    int n = 0;
    cin >> n;
    int seq[n];
    for (int i = 0; i < n; ++i) {
        cin >> seq[i];
    }

    int p[n];
    int subseqlen[n];
    for (int i = 0; i < n; ++i) {
        subseqlen[i] = 1;
        p[i] = -1;
        for (int j = 0; j < i; ++j) {
            if (seq[j] <= seq[i] && subseqlen[i] < subseqlen[j] + 1) {
                subseqlen[i] = subseqlen[j] + 1;
                p[i] = j;
            }
        }
    }

    int answer = subseqlen[0], pos = 0;
    for (int i = 0; i < n; ++i) {
        if (subseqlen[i] > answer) {
            answer = subseqlen[i];
            pos = i;
        }
    }
    cout << answer << endl;

    vector<int> path;
    while (pos != -1) {
        path.push_back(pos);
        pos = p[pos];
    }
    reverse(path.begin(), path.end());
    for (int i : path) {
        cout << i + 1 << " ";
    }
    return 0;
}