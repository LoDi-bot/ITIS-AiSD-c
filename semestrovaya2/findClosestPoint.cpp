#include<iostream>
#include<cmath>

struct pt {
    int x, y, id;
};

bool cmp_x(const pt &a, const pt &b) {
    return a.x < b.x || a.x == b.x && a.y < b.y;
}

bool cmp_y(const pt &a, const pt &b) {
    return a.y < b.y;
}

pt a[INT_MAX];
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
        std::sort(a + l, a + r + 1, &cmp_y);
        return;
    }

    int m = (l + r) >> 1;
    int midx = a[m].x;
    rec(l, m), rec(m + 1, r);
    static pt t[INT_MAX];
    std::merge(a + l, a + m + 1, a + m + 1, a + r + 1, t, &cmp_y);
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
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i].x >> a[i].y;
        a[i].id = i;
    }
    std::sort(a, a + n, &cmp_x);
    mindist = 1E20;
    rec(0, n - 1);
    return 0;
}