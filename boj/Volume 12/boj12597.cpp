#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int TC{};
	cin >> TC;
	for (int tc = 1; tc <= TC; ++tc) {
		int N{}, T{}, E{};
		cin >> N >> T >> E;
		vector<vector<int>> A(N + 1);
		while (E--) {
			int x{}, y{};
			cin >> x >> y;
			A[x].push_back(y);
		}
		vector<int> B(N + 1);
		for (int i = 1; i <= N; ++i) {
			if (i == T) {
				continue;
			}
			int sum = accumulate(A[i].begin(), A[i].end(), 0);
			if (A[i].size() > sum) {
				B[i] = -1;
				break;
			}
			sort(A[i].rbegin(), A[i].rend());
			for (int j = A[i].size() - 1; j >= 0; --j) {
				sum -= A[i][j];
				if (A[i].size() > sum) {
					B[i] = j + 1;
					break;
				}
			}
		}
		cout << "Case #" << tc << ": ";
		if (count(B.begin(), B.end(), -1)) {
			cout << "IMPOSSIBLE\n";
		} else {
			for (int i = 1; i <= N; ++i) {
				cout << B[i] << (i == N ? "\n" : " ");
			}
		}
	}
	return 0;
}
