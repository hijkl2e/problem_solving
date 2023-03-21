#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using iii = tuple<int, int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<ll> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	iii ans{A[0], A[1], A[N - 1]};
	ll S = abs(A[0] + A[1] + A[N - 1]);
	for (int i = 0; i < N - 2; ++i) {
		int p1 = i + 1, p2 = N - 1;
		while (p1 < p2) {
			ll X = A[i] + A[p1] + A[p2];
			if (S > abs(X)) {
				ans = {A[i], A[p1], A[p2]};
				S = abs(X);
			}
			if (X < 0) {
				++p1;
			} else {
				--p2;
			}
		}
	}
	auto &[x, y, z] = ans;
	cout << x << " " << y << " " << z << "\n";
	return 0;
}
