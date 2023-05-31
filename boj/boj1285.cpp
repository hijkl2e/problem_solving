#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	vector<string> B(A.begin(), A.end());
	for (auto &s : B) {
		for (auto &c : s) {
			c = c == 'H' ? 'T' : 'H';
		}
	}
	vector<int> C(N);
	int ans = 1e9;
	for (int i = 0; i < (1 << N); ++i) {
		fill(C.begin(), C.end(), 0);
		for (int j = 0; j < N; ++j) {
			auto &s = (i & (1 << j)) ? A[j] : B[j];
			for (int k = 0; k < N; ++k) {
				if (s[k] == 'T') {
					++C[k];
				}
			}
		}
		int cnt{};
		for (int j = 0; j < N; ++j) {
			cnt += min(C[j], N - C[j]);
		}
		ans = min(ans, cnt);
	}
	cout << ans << "\n";
	return 0;
}
