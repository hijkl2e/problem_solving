#include <bits/stdc++.h>

using namespace std;

int solve(int x, int y) {
	return (x - y + 8) % 4 == 2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	set<int> S;
	for (int i = 1; i < N; ++i) {
		if (solve(A[i - 1], A[i])) {
			S.insert(S.end(), i);
		}
	}
	while (M--) {
		int q{}, a{}, b{};
		cin >> q >> a >> b;
		--a;
		if (q == 2) {
			--b;
			auto it = S.upper_bound(a);
			cout << (it == S.end() || b < *it) << "\n";
			continue;
		}
		if (a > 0 && solve(A[a - 1], A[a])) {
			S.erase(a);
		}
		if (a + 1 < N && solve(A[a], A[a + 1])) {
			S.erase(a + 1);
		}
		A[a] = b;
		if (a > 0 && solve(A[a - 1], A[a])) {
			S.insert(a);
		}
		if (a + 1 < N && solve(A[a], A[a + 1])) {
			S.insert(a + 1);
		}
	}
	return 0;
}
