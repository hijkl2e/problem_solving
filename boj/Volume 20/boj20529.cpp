#include <bits/stdc++.h>

using namespace std;

int solve(string &s1, string &s2) {
	int ret{};
	for (int i = 0; i < 4; ++i) {
		if (s1[i] != s2[i]) {
			++ret;
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		vector<string> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		sort(A.begin(), A.end());
		vector<string> B;
		for (int i = 0, j = 1; i < N; i = j++) {
			while (j < N && A[i] == A[j]) {
				++j;
			}
			for (int k = min(j - i, 3); k > 0; --k) {
				B.push_back(A[i]);
			}
		}
		int ans = 1e9;
		for (int i = 0; i < B.size(); ++i) {
			for (int j = i + 1; j < B.size(); ++j) {
				for (int k = j + 1; k < B.size(); ++k) {
					ans = min(ans, solve(B[i], B[j]) + solve(B[j], B[k]) + solve(B[k], B[i]));
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
