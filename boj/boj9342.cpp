#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	regex r("[A-F]?A+F+C+[A-F]?");
	int T{};
	cin >> T;
	cin.ignore();
	while (T--) {
		string S;
		getline(cin, S);
		cout << (regex_match(S, r) ? "Infected!" : "Good") << "\n";
	}
	return 0;
}
