#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int solve(vector<int> &A) {
	int ret{};
	priority_queue<int> pq;
	ll sum{};
	for (int x : A) {
		pq.push(x);
		sum += x;
		if (sum > 0) {
			sum -= 2 * pq.top(); pq.pop();
			++ret;
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{}, M{};
		cin >> N >> M;
		vector<int> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		vector<int> B, C;
		for (int i = M; i < N; ++i) {
			B.push_back(-A[i]);
		}
		for (int i = M - 1; i > 0; --i) {
			C.push_back(A[i]);
		}
		int ans = solve(B) + solve(C);
		cout << ans << "\n";
	}
	return 0;
}
