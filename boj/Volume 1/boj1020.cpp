#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<int> A{4, 0, 3, 3, 2, 3, 4, 1, 5, 3};
vector<int> B, C;

bool solve(int n, int x, bool f) {
	if (n == C.size()) {
		return true;
	}
	if (f && n < C.size() - 1) {
		C[n] = B[n];
		if (solve(n + 1, x - A[C[n]], true)) {
			return true;
		}
	}
	for (int i = f ? B[n] + 1 : 0; i < 10; ++i) {
		if (0 <= x - A[i] && x - A[i] <= 5 * (C.size() - n - 1)) {
			C[n] = i;
			if (solve(n + 1, x - A[i], false)) {
				return true;
			}
			break;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	B.resize(S.size());
	for (int i = 0; i < B.size(); ++i) {
		B[i] = S[i] - '0';
	}
	int x{};
	for (int i = 0; i < B.size(); ++i) {
		x += A[B[i]];
	}
	C.resize(B.size());
	if (!solve(0, x, true)) {
		solve(0, x, false);
	}
	ll ans{}, y = 1;
	for (int i = C.size() - 1; i >= 0; --i) {
		ans += y * (C[i] - B[i]);
		y *= 10;
	}
	ans = (ans + y) % y;
	ans = ans ? ans : y;
	cout << ans << "\n";
	return 0;
}
