#include <bits/stdc++.h>

using namespace std;

using dii = tuple<double, int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int M{};
	cin >> M;
	double minv = *min_element(A.begin(), A.end());
	priority_queue<dii> pq;
	for (int i = 0; i < N; ++i) {
		pq.push({A[i], A[i], 1});
	}
	double ans = get<0>(pq.top()) - minv;
	while (M--) {
		auto [x, y, z] = pq.top(); pq.pop();
		double val = y * 1.0 / (z + 1);
		pq.push({val, y, z + 1});
		minv = min(minv, val);
		ans = min(ans, get<0>(pq.top()) - minv);
	}
	cout << fixed << setprecision(10);
	cout << ans << "\n";
	return 0;
}
