#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int a{}, b{};
		cin >> a >> b;
		cin.ignore();
		string S;
		getline(cin, S);
		for (auto &c : S) {
			c = (a * (c - 'A') + b) % 26 + 'A';
		}
		cout << S << "\n";
	}
	return 0;
}
