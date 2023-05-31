#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		vector<int> A(N, -1);
		vector<int> B(N, -1);
		vector<int> C{0};
		for (int i = 0, k = N > 1; A[0] == -1; ++i) {
			int sz = C.size();
			for (int j = 0; j < sz; ++j) {
				int x = (C[j] + k) % N;
				if (A[x] == -1) {
					A[x] = i;
					B[x] = C[j];
					C.push_back(x);
				}
			}
			k = 10 * k % N;
		}
		string ans(A[0] + 1, '0');
		int x{};
		while (B[x]) {
			ans[A[x]] = '1';
			x = B[x];
		}
		ans[A[x]] = '1';
		reverse(ans.begin(), ans.end());
		cout << ans << "\n";
	}
	return 0;
}
