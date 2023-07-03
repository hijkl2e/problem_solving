#include <bits/stdc++.h>

using namespace std;

int N;
vector<char> A;

void solve(int n) {
	if (n == N - 1) {
		int x{}, y{};
		char c = '+';
		for (int i = 1; i <= N; ++i) {
			y = 10 * y + i;
			if (A[i - 1] == ' ') {
				continue;
			}
			x += (c == '+' ? 1 : -1) * y;
			y = 0;
			c = A[i - 1];
		}
		if (x == 0) {
			for (int i = 1; i <= N; ++i) {
				cout << i << (i == N ? '\n' : A[i - 1]);
			}
		}
		return;
	}
	A[n] = ' ';
	solve(n + 1);
	A[n] = '+';
	solve(n + 1);
	A[n] = '-';
	solve(n + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	for (int tc = 0; tc < T; ++tc) {
		if (tc) {
			cout << "\n";
		}
		cin >> N;
		A.resize(N);
		A[N - 1] = '+';
		solve(0);
	}
	return 0;
}
