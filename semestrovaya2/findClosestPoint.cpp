#include<iostream>
#include<cmath>
#include<algorithm>
#include<ctime>
#include<fstream>

using namespace std;

struct pt {
    int x, y, id;
};

bool cmp_x(const pt &a, const pt &b) {
    return a.x < b.x || a.x == b.x && a.y < b.y;
}

bool cmp_y(const pt &a, const pt &b) {
    return a.y < b.y;
}

pt a[INT16_MAX];
double mindist;
int ansa, ansb;

void upd_ans(const pt &first, const pt &b) {
    double dist = sqrt((first.x - b.x) * (first.x - b.x) + (first.y - b.y) * (first.y - b.y));
    if (dist < mindist)
        mindist = dist, ansa = first.id, ansb = b.id;
}

void rec(int l, int r) {
    if (r - l <= 3) {
        for (int i = l; i <= r; ++i)
            for (int j = i + 1; j <= r; ++j)
                upd_ans(a[i], a[j]);
        sort(a + l, a + r + 1, &cmp_y);
        return;
    }

    int m = (l + r) >> 1;
    int midx = a[m].x;
    rec(l, m), rec(m + 1, r);
    static pt t[INT16_MAX];
    merge(a + l, a + m + 1, a + m + 1, a + r + 1, t, &cmp_y);
    std::copy(t, t + r - l + 1, a + l);

    int tsz = 0;
    for (int i = l; i <= r; ++i)
        if (fabs(a[i].x - midx) < mindist) {
            for (int j = tsz - 1; j >= 0 && a[i].y - t[j].y < mindist; --j)
                upd_ans(a[i], t[j]);
            t[tsz++] = a[i];
        }
}

int main() {

    int n;
    for (int i = 0; i < 60; i++) {

        ifstream fin("D://infa/pskda_aicd/LoDi/DodiTest/test" + to_string(i + 1) + ".txt");

        fin >> n;

        cout << "******************************" << endl;
        cout << "test #" << i + 1 << endl;
        cout << "n: " << n << endl;

        for (int j = 0; j < n; ++j) {
            fin >> a[j].x;
            fin >> a[j].y;
            a[j].id = j;
        }


        sort(a, a + n, &cmp_x);
        mindist = 1E20;


        clock_t start;
        double duration;
        start = clock();

        rec(0, n - 1);
        cout << "answer: " << mindist << endl;

        duration = (clock() - start) / (double) CLOCKS_PER_SEC;
        cout << "time: " << duration << "s" << endl;

    }
    return 0;
}