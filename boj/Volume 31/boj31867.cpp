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
	int a{}, b{};
	for (char c : S) {
		if (c % 2) {
			++a;
		} else {
			++b;
		}
	}
	int ans = a < b ? 0 : a > b ? 1 : -1;
	cout << ans << "\n";
	return 0;
}
