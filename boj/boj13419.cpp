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
		string a, b;
		for (int k = 0; k < 2; ++k) {
			for (int i = 0; i < S.size(); ++i) {
				if (i % 2) {
					b += S[i];
				} else {
					a += S[i];
				}
			}
			if (S.size() % 2 == 0) {
				break;
			}
			swap(a, b);
		}
		cout << a << "\n";
		cout << b << "\n";
	}
	return 0;
}
