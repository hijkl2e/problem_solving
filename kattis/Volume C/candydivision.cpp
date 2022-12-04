#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{};
	cin >> N;
	vector<ll> A;
	for (ll i = 1; i * i <= N; ++i) {
		if (N % i == 0) {
			A.push_back(i - 1);
			if (i * i < N) {
				A.push_back(N / i - 1);
			}
		}
	}
	sort(A.begin(), A.end());
	for (int i = 0; i < A.size(); ++i) {
		cout << A[i] << (i == A.size() - 1 ? "\n" : " ");
	}
	return 0;
}
