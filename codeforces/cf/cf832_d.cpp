#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, Q{};
	cin >> N >> Q;
	vector<int> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	vector<int> pxor(N + 1);
	for (int i = 1; i <= N; ++i) {
		pxor[i] = pxor[i - 1] ^ A[i];
	}
	map<int, vector<int>> i2v[2];
	for (int i = 1; i <= N; ++i) {
		i2v[i % 2][pxor[i]].push_back(i);
	}
	vector<int> Z(N + 1);
	for (int i = 1; i <= N; ++i) {
		Z[i] = Z[i - 1] + (A[i] == 0);
	}
	while (Q--) {
		int l{}, r{}, ans{};
		cin >> l >> r;
		int len = r - l + 1;
		if (Z[r] - Z[l - 1] == len) {
			ans = 0;
		} else if (pxor[r] ^ pxor[l - 1]) {
			ans = -1;
		} else if (len % 2) {
			ans = 1;
		} else {
			auto &v = i2v[(r % 2) ^ 1][pxor[r]];
			auto it = lower_bound(v.begin(), v.end(), l);
			if (it == v.end() || *it > r) {
				ans = -1;
			} else {
				ans = 2;
				if (Z[*it] - Z[l - 1] == (*it - l + 1)) {
					ans = 1;
				}
				it = upper_bound(v.begin(), v.end(), r);
				--it;
				if (Z[r] - Z[*it] == (r - *it)) {
					ans = 1;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
