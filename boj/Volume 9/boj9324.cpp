#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	cin.ignore();
	while (T--) {
		string S;
		getline(cin, S);
		vector<int> A(26);
		bool yes = true;
		for (int i = 0; i < S.size(); ++i) {
			if (++A[S[i] - 'A'] % 3 == 0 && (++i == S.size() || S[i] != S[i - 1])) {
				yes = false;
				break;
			}
		}
		cout << (yes ? "OK" : "FAKE") << "\n";
	}
	return 0;
}
