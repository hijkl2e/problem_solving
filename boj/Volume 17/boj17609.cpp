#include <bits/stdc++.h>

using namespace std;

bool solve(const string &S) {
	string T = S;
	reverse(T.begin(), T.end());
	return S == T;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	cin.ignore();
	while (T--) {
		string S;
		getline(cin, S);
		if (solve(S)) {
			cout << "0\n";
			continue;
		}
		bool yes{};
		for (int i = 0, j = S.size() - i - 1; i < j; ++i, --j) {
			if (S[i] == S[j]) {
				continue;
			}
			if (solve(S.substr(0, i) + S.substr(i + 1))
					|| solve(S.substr(0, j) + S.substr(j + 1))) {
				yes = true;
			}
			break;
		}
		cout << (yes ? 1 : 2) << "\n";
	}
	return 0;
}
