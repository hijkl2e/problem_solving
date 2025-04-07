#include <bits/stdc++.h>

using namespace std;

bool solve(int m, int l, int M, int L, int tm, int tl) {
	if ((0 <= l && l < m && m < L) || (L < m && m < l && l <= 0)) {
		l = m;
	}
	int t = abs(m) + abs(M - m);
	if (t > tm) {
		return false;
	}
	t += abs(l - M) + abs(L - l);
	return t <= tl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int m{}, l{}, M{}, L{}, tm{}, tl{};
	cin >> m >> l >> M >> L >> tm >> tl;
	bool yes = solve(m, l, M, L, tm, tl);
	yes |= solve(l, m, L, M, tl, tm);
	cout << (yes ? "possible" : "impossible") << "\n";
	return 0;
}
