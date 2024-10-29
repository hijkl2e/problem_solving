#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		string S, P;
		cin >> S >> P;
		int k{}, f{}, ans{};
		while ((f = S.find(P, k)) != -1) {
			ans += f - k + 1;
			k = f + P.size();
		}
		ans += S.size() - k;
		cout << ans << "\n";
	}
	return 0;
}
