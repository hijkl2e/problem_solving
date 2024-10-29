#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	while (getline(cin, S), S != "#") {
		int sum{};
		for (int i = 0; i < S.size(); ++i) {
			if (S[i] == ' ') {
				continue;
			}
			sum += (i + 1) * (S[i] - 'A' + 1);
		}
		cout << sum << "\n";
	}
	return 0;
}
