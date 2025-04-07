#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	while (getline(cin, S), S != "0") {
		while (S.size() > 1) {
			int x{};
			for (char c : S) {
				x += c - '0';
			}
			S = to_string(x);
		}
		cout << S << "\n";
	}
	return 0;
}
