#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> fact(11);
	fact[0] = 1;
	for (int i = 1; i < 11; ++i) {
		fact[i] = i * fact[i - 1];
	}
	string S;
	int x{};
	while (cin >> S >> x) {
		cout << S << " " << x << " = ";
		if (fact[S.size()] < x--) {
			cout << "No permutation\n";
			continue;
		}
		string ans;
		while (S.size()) {
			int y = x / fact[S.size() - 1];
			x %= fact[S.size() - 1];
			ans += S[y];
			S.erase(S.begin() + y);
		}
		cout << ans << "\n";
	}
	return 0;
}
