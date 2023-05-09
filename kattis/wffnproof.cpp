#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	while (getline(cin, S), S != "0") {
		vector<char> var, op;
		int N{};
		for (char c : S) {
			if (islower(c)) {
				var.push_back(c);
			} else if (c == 'N') {
				++N;
			} else {
				op.push_back(c);
			}
		}
		if (var.empty()) {
			cout << "no WFF possible\n";
			continue;
		}
		string ans = string(N, 'N') + var[0];
		for (int i = 0; i + 1 < var.size() && i < op.size(); ++i) {
			ans = op[i] + ans + var[i + 1];
		}
		cout << ans << "\n";
	}
	return 0;
}
