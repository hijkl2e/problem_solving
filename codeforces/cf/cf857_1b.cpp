#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		vector<ii> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i].first >> A[i].second;
			A[i].first *= -1;
		}
		sort(A.begin(), A.end());
		multiset<int> S;
		for (int i = 0; i < N; ++i) {
			A[i].first *= -1;
			S.insert(A[i].second);
		}
		int ans = INF, x = -INF;
		for (auto &[u, v] : A) {
			ans = min(ans, abs(u - x));
			S.erase(S.find(v));
			auto it = S.lower_bound(u);
			if (it != S.end() && *it >= x) {
				ans = min(ans, *it - u);
			}
			if (it != S.begin() && *--it >= x) {
				ans = min(ans, u - *it);
			}
			x = max(x, v);
		}
		cout << ans << "\n";
	}
	return 0;
}
