#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	while (getline(cin, S), S != "#") {
		int x{};
		for (int i = 0; i < S.size() - 1; ++i) {
			x ^= S[i] - '0';
		}
		S.back() = (x ^ (S.back() == 'o')) + '0';
		cout << S << "\n";
	}
	return 0;
}
