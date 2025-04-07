#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<ll> B(N);
	deque<int> dq;
	for (int i = 0; i < N; ++i) {
		if (dq.size() && i - dq.front() == K + 2) {
			dq.pop_front();
		}
		B[i] = (i > K ? B[dq.front()] : 0) + A[i];
		while (dq.size() && B[dq.back()] >= B[i]) {
			dq.pop_back();
		}
		dq.push_back(i);
	}
	ll ans = accumulate(A.begin(), A.end(), 0LL);
	ans -= (N == K ? 0 : *min_element(B.end() - K - 1, B.end()));
	cout << ans << "\n";
	return 0;
}
