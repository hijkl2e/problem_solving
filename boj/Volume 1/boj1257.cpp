#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll M{}, N{};
	cin >> M >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	ll X = A[N - 1];
	vector<int> D(X, INF);
	deque<int> dq;
	D[0] = 0;
	dq.push_back(0);
	while (dq.size()) {
		int x = dq.front();
		dq.pop_front();
		for (int i = 0; i < N - 1; ++i) {
			int y = x + A[i];
			if (y < X) {
				if (D[y] > D[x] + 1) {
					D[y] = D[x] + 1;
					dq.push_back(y);
				}
			} else {
				y -= X;
				if (D[y] > D[x]) {
					D[y] = D[x];
					dq.push_front(y);
				}
			}
		}
	}
	ll ans = M / X + D[M % X];
	cout << ans << "\n";
	return 0;
}
