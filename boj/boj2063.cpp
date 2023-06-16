#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const double EPS = 1e-9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		vector<ll> A(N);
		for (int i = 0; i < N; ++i) {
			double x{};
			cin >> x;
			A[i] = 1000 * x + EPS;
		}
		sort(A.rbegin(), A.rend());
		ll sum = accumulate(A.begin(), A.end(), 0LL);
		bool yes{};
		for (int i = 0; i < N; ++i) {
			sum -= A[i];
			if (A[i] <= sum) {
				yes = true;
				break;
			}
		}
		cout << (yes ? "YES" : "NO") << "\n";
	}
	return 0;
}
