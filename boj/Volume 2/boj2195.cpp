#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S, P;
	getline(cin, S);
	getline(cin, P);
	int ans{};
	for (int i = 0; i < P.size();) {
		int maxv{};
		for (int j = 0; j < S.size(); ++j) {
			int k{};
			while (i + k < P.size() && j + k < S.size() && P[i + k] == S[j + k]) {
				++k;
			}
			maxv = max(maxv, k);
		}
		i += maxv;
		++ans;
	}
	cout << ans << "\n";
	return 0;
}
