#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S, T;
	while (cin >> S >> T) {
		int p{};
		for (int i = 0; i < T.size() && p < S.size(); ++i) {
			if (S[p] == T[i]) {
				++p;
			}
		}
		cout << (p == S.size() ? "Yes" : "No") << "\n";
	}
	return 0;
}
