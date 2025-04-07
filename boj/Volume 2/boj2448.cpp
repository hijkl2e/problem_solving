#include <bits/stdc++.h>

using namespace std;

const int dx[8]{0, 1, 1, 2, 2, 2, 2, 2};
const int dy[8]{2, 1, 3, 0, 1, 2, 3, 4};

vector<string> A;

void solve(int x, int y, int sz) {
	if (sz == 3) {
		for (int i = 0; i < 8; ++i) {
			A[x + dx[i]][y + dy[i]] = '*';
		}
		return;
	}
	sz /= 2;
	solve(x, y + sz, sz);
	solve(x + sz, y, sz);
	solve(x + sz, y + 2 * sz, sz);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	A.assign(N, string(2 * N - 1, ' '));
	solve(0, 0, N);
	for (auto &s : A) {
		cout << s << "\n";
	}
	return 0;
}
