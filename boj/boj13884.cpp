#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int K{}, N{};
		cin >> K >> N;
		vector<int> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		vector<int> B(A.begin(), A.end());
		sort(B.begin(), B.end());
		int ans = N;
		for (int i = 0; i < N; ++i) {
			if (A[i] == B[N - ans]) {
				--ans;
			}
		}
		cout << K << " " << ans << "\n";
	}
	return 0;
}
