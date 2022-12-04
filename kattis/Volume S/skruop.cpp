#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int x = 7;
	while (N--) {
		string s;
		cin >> s;
		cin >> s;
		if (s == "op!") {
			x = min(x + 1, 10);
		} else {
			x = max(x - 1, 0);
		}
	}
	cout << x << "\n";
	return 0;
}
