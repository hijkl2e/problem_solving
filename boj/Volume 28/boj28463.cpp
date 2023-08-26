#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	for (int i = 0; i < 3; ++i) {
		string s;
		cin >> s;
		S += s;
	}
	string ans = "?";
	if (S == "EO..P" || S == "WP..O" || S == "S.OP." || S == "N.PO.") {
		ans = "T";
	} else if (S == "E.PI." || S == "W.IP." || S == "SI..P" || S == "NP..I") {
		ans = "F";
	} else if (S == "E.PO." || S == "W.OP." || S == "SO..P" || S == "NP..O") {
		ans = "Lz";
	}
	cout << ans << "\n";
	return 0;
}
