#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	int x{}, y{};
	for (int i = 0; i < S.size(); ++i) {
		if (S.substr(i, 3) == ":-)") {
			++x;
		} else if (S.substr(i, 3) == ":-(") {
			++y;
		}
	}
	cout << (x + y == 0 ? "none" : x == y ? "unsure" : x > y ? "happy" : "sad") << "\n";
	return 0;
}
