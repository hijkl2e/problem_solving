#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 4e18;

ll N, M, K;

vector<ll> solve(deque<bool> &A) {
	vector<ll> B(N, -INF);
	queue<int> q;
	int cnt{};
	B[(M + K) / 2 - 1] = 0;
	for (int i = 0; i < (M + K) / 2; ++i) {
		if (A[i]) {
			++cnt;
			continue;
		}
		B[(M + K) / 2 - 1] += i;
		q.push(cnt);
	}
	for (int i = (M + K) / 2; i < N; ++i) {
		if (A[i] && q.empty()) {
			break;
		}
		B[i] = B[i - 1];
		if (q.empty()) {
			continue;
		}
		B[i] -= q.front(); q.pop();
		B[i] -= q.size();
		if (A[i]) {
			++cnt;
		} else {
			B[i] += (M + K) / 2 - 1;
			q.push(cnt);
		}
	}
	return B;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M >> K;
	deque<bool> A(N);
	for (int i = 0; i < M; ++i) {
		int x{};
		cin >> x;
		A[x - 1] = true;
	}
	vector<ll> L = solve(A);
	reverse(A.begin(), A.end());
	vector<ll> R = solve(A);
	reverse(R.begin(), R.end());
	reverse(A.begin(), A.end());
	ll ans{};
	if ((M + K) % 2) {
		for (int i = 1; i < N - 1; ++i) {
			ans = max(ans, L[i - 1] + R[i + 1] + (A[i] ? 0 : (M + K) / 2));
		}
	} else {
		for (int i = 1; i < N; ++i) {
			ans = max(ans, L[i - 1] + R[i]);
		}
	}
	ans = K * (2 * M + K - 1) / 2 - 2 * ans;
	cout << ans << "\n";
	return 0;
}
