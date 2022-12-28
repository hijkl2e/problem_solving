#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	cin.ignore();
	while (T--) {
		string S;
		getline(cin, S);
		int len = sqrt(S.size()) + EPS;
		for (int i = len - 1; i >= 0; --i) {
			for (int j = 0; j < S.size(); j += len) {
				cout << S[i + j];
			}
		}
		cout << "\n";
	}
	return 0;
}
