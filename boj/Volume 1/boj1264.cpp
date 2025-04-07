#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	while (getline(cin, S), S != "#") {
		int cnt{};
		for (char c : S) {
			c = tolower(c);
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
				++cnt;
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}
