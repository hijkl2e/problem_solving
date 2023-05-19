#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		N += 2;
		vector<int> x(N);
		vector<int> y(N);
		for (int i = 0; i < N; ++i) {
			cin >> x[i] >> y[i];
		}
		deque<bool> vst(N);
		queue<int> q;
		vst[0] = true;
		q.push(0);
		while (q.size()) {
			int u = q.front(); q.pop();
			for (int i = 0; i < N; ++i) {
				if (vst[i] || abs(x[u] - x[i]) + abs(y[u] - y[i]) > 1000) {
					continue;
				}
				vst[i] = true;
				q.push(i);
			}
		}
		cout << (vst[N - 1] ? "happy" : "sad") << "\n";
	}
	return 0;
}
