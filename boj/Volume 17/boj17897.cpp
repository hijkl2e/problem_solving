#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	string ans;
	while (N--) {
		int K{};
		cin >> K;
		cin.ignore();
		string rest;
		getline(cin, rest);
		bool soup{}, cake{};
		while (K--) {
			string menu;
			getline(cin, menu);
			soup |= menu == "pea soup";
			cake |= menu == "pancakes";
		}
		if (soup && cake) {
			ans = rest;
			break;
		}
	}
	if (ans.size()) {
		cout << ans << "\n";
	} else {
		cout << "Anywhere is fine I guess\n";
	}
	return 0;
}
