#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{}, K{};
	cin >> N >> K;
	vector<int> A;
	while (N) {
		A.push_back(N % K);
		N /= K;
	}
	reverse(A.begin(), A.end());
	vector<ll> B;
	ll x{};
	for (int i = 0; i < A.size(); ++i) {
		if (A[i]) {
			x = 10 * x + A[i];
		} else {
			B.push_back(x);
			x = 0;
		}
	}
	B.push_back(x);
	N = accumulate(B.begin(), B.end(), 0LL);
	A.clear();
	while (N) {
		A.push_back(N % K);
		N /= K;
	}
	reverse(A.begin(), A.end());
	for (int i = 0; i < A.size(); ++i) {
		cout << A[i];
	}
	cout << "\n";
	return 0;
}
