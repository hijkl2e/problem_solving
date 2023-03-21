#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

void solve(int &x, int &y, int k) {
	x ^= k ? (7 << (k - 1)) : 3;
	y ^= 1 << k;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(10);
	for (int i = 0; i < 10; ++i) {
		string s;
		getline(cin, s);
		for (char c : s) {
			A[i] = 2 * A[i] + (c == 'O');
		}
	}
	vector<int> B(11);
	int ans = INF;
	for (int i = 0; i < 1024; ++i) {
		int cnt{};
		copy(A.begin(), A.end(), B.begin());
		for (int j = 0; j < 10; ++j) {
			if (i & (1 << j)) {
				solve(B[0], B[1], j);
				++cnt;
			}
		}
		for (int j = 0; j < 9; ++j) {
			for (int k = 0; k < 10; ++k) {
				if (B[j] & (1 << k)) {
					solve(B[j + 1], B[j + 2], k);
					++cnt;
				}
			}
		}
		if ((B[9] & 1023) == 0) {
			ans = min(ans, cnt);
		}
	}
	cout << (ans == INF ? -1 : ans) << "\n";
	return 0;
}
