#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<vector<int>> A(N, vector<int>(3));
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[j][i];
		}
	}
	int x = -1;
	bool yes = true;
	for (int i = 0; i < N; ++i) {
		sort(A[i].begin(), A[i].end());
		if (x + 1 > A[i][2]) {
			yes = false;
			break;
		}
		x = max(x + 1, A[i][0]);
	}
	cout << (yes ? "YES" : "NO") << "\n";
	return 0;
}
