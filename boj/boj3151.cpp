#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
		A[i] += 10000;
	}
	vector<ll> B(20001);
	for (int i = 0; i < N; ++i) {
		++B[A[i]];
	}
	ll ans{};
	for (int i = 5000; i < 15001; ++i) {
		if (i == 10000) {
			ans += B[i] * (B[i] - 1) * (B[i] - 2) / 6;
		} else {
			ans += B[i] * (B[i] - 1) * B[30000 - 2 * i] / 2;
		}
	}
	sort(A.begin(), A.end());
	A.resize(unique(A.begin(), A.end()) - A.begin());
	for (int i = 0; i < A.size(); ++i) {
		int s = i + 1, e = A.size() - 1;
		while (s < e) {
			int sum = A[i] + A[s] + A[e];
			if (sum < 30000) {
				++s;
			} else if (sum > 30000) {
				--e;
			} else {
				ans += B[A[i]] * B[A[s++]] * B[A[e--]];
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
