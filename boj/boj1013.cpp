#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	regex r("(100+1+|01)+");
	int T{};
	cin >> T;
	cin.ignore();
	while (T--) {
		string S;
		getline(cin, S);
		cout << (regex_match(S, r) ? "YES" : "NO") << "\n";
	}
	return 0;
}
