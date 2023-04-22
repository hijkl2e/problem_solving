#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, D{};
	cin >> N >> D;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<ll> B(N);
	deque<int> dq;
	for (int i = 0; i < N; ++i) {
		if (dq.size() && i - dq.front() == D + 1) {
			dq.pop_front();
		}
		B[i] = (dq.size() ? B[dq.front()] : 0) + A[i];
		while (dq.size() && B[dq.back()] <= B[i]) {
			dq.pop_back();
		}
		if (B[i] > 0) {
			dq.push_back(i);
		}
	}
	ll ans = *max_element(B.begin(), B.end());
	cout << ans << "\n";
	return 0;
}
