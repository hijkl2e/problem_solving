#include <bits/stdc++.h>

using namespace std;

using di = pair<double, int>;

const double EPS = 1e-9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	double T{};
	int N{};
	cin >> T >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	double minv = *min_element(A.begin(), A.end());
	priority_queue<di> pq;
	for (int i = 0; i < N; ++i) {
		pq.push({A[i], 1});
	}
	int ans{};
	while (minv < T * pq.top().first + EPS) {
		auto [x, y] = pq.top(); pq.pop();
		double val = x * y / (y + 1);
		pq.push({val, y + 1});
		minv = min(minv, val);
		++ans;
	}
	cout << ans << "\n";
	return 0;
}
