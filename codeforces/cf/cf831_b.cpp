#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		vector<int> A(N);
		vector<int> B(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i] >> B[i];
			if (A[i] > B[i]) {
				swap(A[i], B[i]);
			}
		}
		ll ans = accumulate(A.begin(), A.end(), 0LL);
		ans += *max_element(B.begin(), B.end());
		ans *= 2;
		cout << ans << "\n";
	}
	return 0;
}
