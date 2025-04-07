#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int ar{}, ac{}, tr{}, tc{};
	while (cin >> ar >> ac >> tr >> tc) {
		cin.ignore();
		vector<string> A(ar + 2 * tr, string(ac + 2 * tc, '.'));
		for (int i = 0; i < ar; ++i) {
			getline(cin, A[i + tr]);
			A[i + tr] = string(tc, '.') + A[i + tr] + string(tc, '.');
		}
		ar += 2 * tr;
		ac += 2 * tc;
		vector<vector<int>> B(ar, vector<int>(ac));
		for (int i = 0; i < ar; ++i) {
			for (int j = 0; j < ac; ++j) {
				B[i][j] = (i ? B[i - 1][j] : 0) + (j ? B[i][j - 1] : 0)
						- (i && j ? B[i - 1][j - 1] : 0) + (A[i][j] == 'X');
			}
		}
		int ans = 1e9;
		for (int i = 0; i < tr; ++i) {
			for (int j = 0; j < tc; ++j) {
				int cnt{};
				for (int k = i; k + tr < ar; k += tr) {
					for (int l = j; l + tc < ac; l += tc) {
						if (B[k + tr][l + tc] - B[k][l + tc] - B[k + tr][l] + B[k][l]) {
							++cnt;
						}
					}
				}
				ans = min(ans, cnt);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
