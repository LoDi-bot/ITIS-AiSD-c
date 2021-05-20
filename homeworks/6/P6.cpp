#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100000;
int node[maxn];
struct Edge{
    int x, y;
    int w;
};
Edge arr[maxn];
bool cmp(const Edge& a, const Edge& b){
    return a.w < b.w;
}
int find(int x){
    if (x == node[x]){
        return x;
    } else{
        return node[x] = find(node[x]);
    }
}
void unite(int x, int y){
    int a = find(x);
    int b = find(y);
    node[a] = b;
}

int main() {
    int n, m;
    cin >> n >> m;
    int check[n];
    for (int i=0; i<n; i++){
        check[i] = 0;
        node[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        arr[i].x = a;
        check[a-1]++;
        check[b-1]++;
        arr[i].y = b;
        arr[i].w = c;
    }
    for (int i=0; i<n; i++){
        if (check[i] == 0){
            cout << -1;
            return 0;
        }
    }
    int sum = 0;
    sort(arr, arr+m, cmp);
    for (int i=0; i<m; i++){
        int a = arr[i].x;
        int b = arr[i].y;
        if (find(a) != find(b)) {
            unite(a, b);
            sum += arr[i].w;
        }
    }
    cout << sum;
    return 0;
}