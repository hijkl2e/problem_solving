#include <bits/stdc++.h>

using namespace std;

vector<string> A;

void solve(int x, int y, int sz) {
	if (sz == 1) {
		A[x][y] = '*';
		return;
	}
	sz /= 3;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (i == 1 && j == 1) {
				continue;
			}
			solve(x + i * sz, y + j * sz, sz);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	A.assign(N, string(N, ' '));
	solve(0, 0, N);
	for (auto &s : A) {
		cout << s << "\n";
	}
	return 0;
}
