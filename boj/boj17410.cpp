#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	int sq = sqrt(N) + 1;
	vector<vector<int>> B(sq + 1);
	for (int i = 1; i <= N; ++i) {
		B[i / sq].push_back(A[i]);
	}
	for (int i = 0; i < B.size(); ++i) {
		sort(B[i].begin(), B[i].end());
	}
	int M{};
	cin >> M;
	while (M--) {
		int q{}, a{}, b{}, c{};
		cin >> q >> a >> b;
		if (q == 1) {
			auto &v = B[a / sq];
			auto it = lower_bound(v.begin(), v.end(), A[a]);
			v.erase(it);
			it = lower_bound(v.begin(), v.end(), A[a] = b);
			v.insert(it, A[a]);
			continue;
		}
		cin >> c;
		int ans{};
		int x = a / sq, y = b / sq;
		if (x == y) {
			for (int i = a; i <= b; ++i) {
				if (A[i] > c) {
					++ans;
				}
			}
			cout << ans << "\n";
			continue;
		}
		for (int i = x + 1; i < y; ++i) {
			auto &v = B[i];
			ans += v.size() - (upper_bound(v.begin(), v.end(), c) - v.begin());
		}
		x *= sq, y *= sq;
		for (int i = a % sq; i < sq; ++i) {
			if (A[x + i] > c) {
				++ans;
			}
		}
		for (int i = b % sq; i >= 0; --i) {
			if (A[y + i] > c) {
				++ans;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
