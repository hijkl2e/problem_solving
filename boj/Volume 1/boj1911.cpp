#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, L{};
	cin >> N >> L;
	vector<ii> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i].first >> A[i].second;
	}
	sort(A.begin(), A.end());
	int ans{}, p{};
	for (int i = 0; i < N; ++i) {
		p = max(p, A[i].first);
		if (p < A[i].second) {
			int cnt = (A[i].second - p - 1) / L + 1;
			ans += cnt;
			p += cnt * L;
		}
	}
	cout << ans << "\n";
	return 0;
}
