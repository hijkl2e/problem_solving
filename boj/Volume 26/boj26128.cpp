#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> P(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> P[i];
	}
	vector<int> A(N + 1);
	for (int i = 0; i < M; ++i) {
		int x{};
		cin >> x;
		++A[x];
	}
	vector<int> ind(N + 1);
	for (int i = 1; i <= N; ++i) {
		++ind[P[i]];
	}
	queue<int> q;
	for (int i = 1; i <= N; ++i) {
		if (ind[i] == 0) {
			q.push(i);
		}
	}
	ll ans{};
	while (q.size()) {
		int u = q.front(); q.pop();
		if (A[u] == M) {
			cout << ans << "\n";
			return 0;
		}
		int v = P[u];
		A[v] += A[u];
		ans += A[u];
		A[u] = 0;
		if (--ind[v] == 0) {
			q.push(v);
		}
	}
	vector<ll> B;
	for (int i = 1; i <= N; ++i) {
		if (A[i]) {
			int j = i;
			do {
				B.push_back(A[j]);
				j = P[j];
			} while (i != j);
			break;
		}
	}
	if (accumulate(B.begin(), B.end(), 0) < M) {
		cout << "-1\n";
		return 0;
	}
	ll x{};
	for (int i = 1; i < B.size(); ++i) {
		x += (B.size() - i) * B[i];
	}
	ll minv = x;
	for (int i = 1; i < B.size(); ++i) {
		x = x + M - B.size() * B[i];
		minv = min(minv, x);
	}
	ans += minv;
	cout << ans << "\n";
	return 0;
}
