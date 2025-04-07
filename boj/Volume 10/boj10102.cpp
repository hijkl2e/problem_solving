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
		if (c == 'A') {
			++x;
		} else {
			++y;
		}
	}
	cout << (x > y ? "A" : x < y ? "B" : "Tie") << "\n";
	return 0;
}
