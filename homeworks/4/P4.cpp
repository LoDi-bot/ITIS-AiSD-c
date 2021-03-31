#include <iostream>
#include <vector>

using namespace std;

vector<int> component;

void dfs(int** matr, int n, int vertex, bool* used) {
	used[vertex] = true;
	component.push_back(vertex);
	for (int i = 0; i < n; i++) {
		if (matr[vertex][i] > 0 && !used[i]) {
			dfs(matr, n, i, used);
		}
	}
}

int find(int** matr, int n, bool* used) {
	for (int i = 0; i < n; i++) {
		used[i] = false;
	}
	int max = 0;
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			component.clear();
			dfs(matr, n, i, used);
			if (component.size() > max) {
				max = component.size();
			}
		}
	}
	return max;
}

int main() {
	int n;
	cin >> n;

	int** matr;
	matr = new int* [n];
	for (int i = 0; i < n; i++) {
		matr[i] = new int[n];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matr[i][j];
		}
	}

	bool* used = new bool[n];
	for (int i = 0; i < n; i++) {
		used[i] = false;
	}

	dfs(matr, n, 3, used);
	for (int i = 0; i < n; i++) {
		cout << boolalpha << used[i] << " ";
	}
	cout << endl << endl;

	cout << find(matr, n, used);

	return 0;
}
