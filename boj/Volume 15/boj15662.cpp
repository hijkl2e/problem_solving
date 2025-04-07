#include <bits/stdc++.h>

using namespace std;

int N;
vector<string> A;

void solve(int x, int y, int d, bool f) {
	if (y == 1) {
		if (x + 1 < N && A[x][2] != A[x + 1][6]) {
			solve(x + 1, 1, d == 1 ? -1 : 1, true);
		}
	} else {
		if (x && A[x][6] != A[x - 1][2]) {
			solve(x - 1, -1, d == 1 ? -1 : 1, true);
		}
	}
	if (f) {
		rotate(A[x].begin(), A[x].begin() + (d == 1 ? 7 : 1), A[x].end());
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	cin.ignore();
	A.resize(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	int K{};
	cin >> K;
	while (K--) {
		int x{}, d{};
		cin >> x >> d;
		--x;
		solve(x, 1, d, false);
		solve(x, -1, d, true);
	}
	int ans{};
	for (int i = 0; i < N; ++i) {
		if (A[i][0] == '1') {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
