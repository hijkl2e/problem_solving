#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(M);
	for (int i = 0; i < M; ++i) {
		cin >> A[i];
	}
	int lo = 0, hi = 1e9;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		ll cnt{};
		for (int i = 0; i < M; ++i) {
			cnt += (A[i] - 1) / mid + 1;
		}
		if (cnt > N) {
			lo = mid;
		} else {
			hi = mid;
		}
	}
	cout << hi << "\n";
	return 0;
}
