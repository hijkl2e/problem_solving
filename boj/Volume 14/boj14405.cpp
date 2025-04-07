#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	int p{};
	while (p < S.size()) {
		if (S.substr(p, 2) == "pi" || S.substr(p, 2) == "ka") {
			p += 2;
		} else if (S.substr(p, 3) == "chu") {
			p += 3;
		} else {
			break;
		}
	}
	cout << (p == S.size() ? "YES" : "NO") << "\n";
	return 0;
}
