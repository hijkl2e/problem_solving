#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	string ucpc = "UCPC";
	int p{};
	for (char c : S) {
		if (c == ucpc[p] && ++p == 4) {
			break;
		}
	}
	cout << "I " << (p == 4 ? "love" : "hate") << " UCPC\n";
	return 0;
}
