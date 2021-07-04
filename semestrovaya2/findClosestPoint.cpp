#import<iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> tax(n);

    for (int i = 0; i < n; i++)
        cin >> tax[i].first >> tax[i].second;

    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int q;
        cin >> q;
        int j = n/2;
        int k = 2;
        while (tax[j].first != q)
            k = k * 2;
            if (tax[j].first > q) {
                j = j - n/k;
            }
        j--;
        cout << tax[j].second * q << endl;
    }
    binary_search(tax[0], tax[n-1], q);
    return 0;
}