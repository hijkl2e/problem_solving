#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<int> x(N + 2);
	vector<int> y(N + 2);
	for (int i = 1; i <= N; ++i) {
		cin >> x[i] >> y[i];
	}
	x[N + 1] = y[N + 1] = 10000;
	int lo = 0, hi = 1415;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		vector<int> D(N + 2, -1);
		queue<int> q;
		q.push(0);
		while (q.size()) {
			int u = q.front(); q.pop();
			for (int i = 1; i < N + 2; ++i) {
				if (D[i] == -1) {
					double d = sqrt(pow(x[u] - x[i], 2) + pow(y[u] - y[i], 2));
					int k = ceil(d / 10 - EPS);
					if (k <= mid) {
						D[i] = D[u] + 1;
						q.push(i);
					}
				}
			}
		}
		if (D[N + 1] == -1 || D[N + 1] > K) {
			lo = mid;
		} else {
			hi = mid;
		}
	}
	cout << hi << "\n";
	return 0;
}
