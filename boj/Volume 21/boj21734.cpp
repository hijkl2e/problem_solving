#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	for (char c : S) {
		int cnt{};
		int x = c;
		while (x) {
			cnt += x % 10;
			x /= 10;
		}
		cout << string(cnt, c) << "\n";
	}
	return 0;
}
