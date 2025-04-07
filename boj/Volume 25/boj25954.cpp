#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string A, B;
	getline(cin, A);
	getline(cin, B);
	int na = A.size();
	int nb = B.size();
	A = "#" + A;
	B = "#" + B;
	vector<vector<int>> ih(na + 1, vector<int>(nb + 1));
	vector<vector<int>> iv(na + 1, vector<int>(nb + 1));
	for (int i = 0; i <= nb; ++i) {
		ih[0][i] = i;
	}
	for (int i = 1; i <= na; ++i) {
		for (int j = 1; j <= nb; ++j) {
			if (A[i] == B[j]) {
				ih[i][j] = iv[i][j - 1];
				iv[i][j] = ih[i - 1][j];
			} else {
				ih[i][j] = max(iv[i][j - 1], ih[i - 1][j]);
				iv[i][j] = min(iv[i][j - 1], ih[i - 1][j]);
			}
		}
	}
	ll ans{};
	for (int i = 1; i <= na; ++i) {
		for (int j = 1; j <= nb; ++j) {
			ans += (j - ih[i][j]) * (nb - j + 1);
		}
	}
	cout << ans << "\n";
	return 0;
}
