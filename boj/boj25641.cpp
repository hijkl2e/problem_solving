#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	string S;
	getline(cin, S);
	int x{}, y{};
	for (char c : S) {
		if (c == 's') {
			++x;
		} else {
			++y;
		}
	}
	int p{};
	for (; x != y; ++p) {
		if (S[p] == 's') {
			--x;
		} else {
			--y;
		}
	}
	cout << S.substr(p) << "\n";
	return 0;
}
