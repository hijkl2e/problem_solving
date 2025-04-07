#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, a{}, b{};
	cin >> N >> a >> b;
	--a, --b;
	vector<vector<int>> A(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
		}
	}
	bool yes{};
	for (int i = 0; i < N; ++i) {
		if (A[i][b] > A[a][b] || A[a][i] > A[a][b]) {
			yes = true;
			break;
		}
	}
	cout << (yes ? "ANGRY" : "HAPPY") << "\n";
	return 0;
}
