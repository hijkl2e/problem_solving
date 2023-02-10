#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	int ans = S.size();
	for (int i = 0; i < S.size(); ++i) {
		if (S.substr(i, 2) == "lj" || S.substr(i, 2) == "nj" || S.substr(i, 3) == "dz=") {
			--ans;
		}
	}
	ans -= count(S.begin(), S.end(), '-');
	ans -= count(S.begin(), S.end(), '=');
	cout << ans << "\n";
	return 0;
}
