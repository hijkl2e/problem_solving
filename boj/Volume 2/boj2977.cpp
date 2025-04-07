#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> X, Y, Sm, Pm, Sv, Pv;

int solve(int x, int sm, int pm, int sv, int pv) {
	int ret = 1e9;
	for (int j = 0;; ++j) {
		int y = max(x - j * sv, 0);
		if (y == 0) {
			ret = min(ret, j * pv);
			break;
		}
		ret = min(ret, j * pv + ((y - 1) / sm + 1) * pm);
	}
	return ret;
}

int solve(int x) {
	int ret{};
	for (int i = 0; i < N && ret <= M; ++i) {
		ret += solve(max(x * X[i] - Y[i], 0), Sm[i], Pm[i], Sv[i], Pv[i]);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M;
	X.resize(N);
	Y.resize(N);
	Sm.resize(N);
	Pm.resize(N);
	Sv.resize(N);
	Pv.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> X[i] >> Y[i] >> Sm[i] >> Pm[i] >> Sv[i] >> Pv[i];
	}
	int lo = 0, hi = 1e5;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		if (solve(mid) <= M) {
			lo = mid;
		} else {
			hi = mid;
		}
	}
	cout << lo << "\n";
	return 0;
}
