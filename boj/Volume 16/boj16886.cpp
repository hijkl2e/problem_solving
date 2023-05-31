#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> dp(N + 1);
	vector<int> par(N + 1, -1);
	vector<int> pxor(N + 1);
	deque<bool> vst(16);
	for (int i = 2; i <= N; ++i) {
		fill(vst.begin(), vst.end(), false);
		for (int j = 2; j * (j + 1) / 2 <= i; ++j) {
			int k = j * (j + 1) / 2;
			if ((i - k) % j) {
				continue;
			}
			int q = (i - k) / j;
			int res = pxor[q + j] ^ pxor[q];
			vst[res] = true;
			if (res == 0 && par[i] == -1) {
				par[i] = j;
			}
		}
		for (int j = 0; vst[j]; ++j) {
			dp[i] = j + 1;
		}
		pxor[i] = pxor[i - 1] ^ dp[i];
	}
	cout << par[N] << "\n";
	return 0;
}
