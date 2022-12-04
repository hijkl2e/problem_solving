#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, T{};
	cin >> N >> T;
	vector<ii> R, S;
	for (int i = 0; i < N; ++i) {
		int d{}, k{};
		char c{};
		cin >> d >> c >> k;
		if (c == 'R') {
			R.push_back({d, k});
		} else {
			S.push_back({d, k});
		}
	}
	sort(R.begin(), R.end());
	sort(S.begin(), S.end());
	priority_queue<int, vector<int>, greater<int>> pq;
	while (T--) {
		pq.push(0);
	}
	ll r_sum{}, s_sum{};
	for (int i = 0, j = 0; i < R.size() || j < S.size();) {
		int t = pq.top(); pq.pop();
		if (j < S.size() && (i == R.size() || S[j].first <= max(t, R[i].first))) {
			s_sum += max(t - S[j].first, 0) + S[j].second;
			t = max(t, S[j].first) + S[j].second;
			++j;
		} else {
			r_sum += max(t - R[i].first, 0) + R[i].second;
			t = max(t, R[i].first) + R[i].second;
			++i;
		}
		pq.push(t);
	}
	double o = S.size() ? s_sum * 1.0 / S.size() : 0;
	double r = R.size() ? r_sum * 1.0 / R.size() : 0;
	cout << fixed << setprecision(10);
	cout << o << " " << r << "\n";
	return 0;
}
