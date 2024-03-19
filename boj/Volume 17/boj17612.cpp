#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	for (int i = 0; i < K; ++i) {
		pq.push({0, i});
	}
	vector<iii> A(N);
	for (int i = 0; i < N; ++i) {
		int x{}, y{};
		cin >> x >> y;
		auto [t, j] = pq.top(); pq.pop();
		t += y;
		A[i] = {t, -j, x};
		pq.push({t, j});
	}
	sort(A.begin(), A.end());
	ll ans{};
	for (int i = 0; i < N; ++i) {
		ans += (i + 1LL) * get<2>(A[i]);
	}
	cout << ans << "\n";
	return 0;
}
