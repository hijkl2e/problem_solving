#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	ll lo = 0, hi = 1e18;
	while (lo + 1 < hi) {
		ll mid = (lo + hi) / 2;
		__int128 cnt{};
		for (int i = 0; i < N; ++i) {
			cnt += mid / A[i];
		}
		if (cnt < M) {
			lo = mid;
		} else {
			hi = mid;
		}
	}
	cout << hi << "\n";
	return 0;
}
