#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<vector<int>> A(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
		}
	}
	int sx{}, sy{};
	vector<ii> B;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (A[i][j] == 2) {
				sx = i, sy = j;
			} else if (A[i][j] == 1) {
				B.push_back({i, j});
			}
		}
	}
	B.insert(B.begin(), {sx, sy});
	bool yes = true;
	for (auto &[x, y] : B) {
		if ((sx + sy + x + y) % 2) {
			yes = false;
			break;
		}
	}
	if (!yes) {
		cout << "Shorei\n";
		return 0;
	}
	for (auto &[x, y] : B) {
		int d1 = x + y;
		int d2 = x - y + N - 1;
		x = d1, y = d2;
	}
	vector<int> C(B.size());
	for (int i = 0; i < C.size(); ++i) {
		C[i] = i;
	}
	int ans = 1e9;
	do {
		int cnt{};
		for (int i = 1; i < B.size(); ++i) {
			auto &[x1, y1] = B[C[i - 1]];
			auto &[x2, y2] = B[C[i]];
			cnt += abs(x2 - x1) + abs(y2 - y1);
		}
		ans = min(ans, cnt / 2);
	} while (next_permutation(C.begin(), C.end()) && C[0] == 0);
	cout << "Undertaker\n" << ans << "\n";
	return 0;
}
