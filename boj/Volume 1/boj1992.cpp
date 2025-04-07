#include <bits/stdc++.h>

using namespace std;

vector<string> A;

void solve(int x, int y, int sz) {
	int cnt{};
	for (int i = 0; i < sz; ++i) {
		for (int j = 0; j < sz; ++j) {
			if (A[x + i][y + j] == A[x][y]) {
				++cnt;
			}
		}
	}
	if (cnt == sz * sz) {
		cout << A[x][y];
		return;
	}
	cout << "(";
	sz /= 2;
	for (int i = 0; i < 4; ++i) {
		solve(x + i / 2 * sz, y + i % 2 * sz, sz);
	}
	cout << ")";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	A.resize(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	solve(0, 0, N);
	cout << "\n";
	return 0;
}
