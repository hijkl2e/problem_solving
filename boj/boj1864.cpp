#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string tab = "/-\\(@?>&%";
	string S;
	while (getline(cin, S), S != "#") {
		int x{};
		for (char c : S) {
			x = 8 * x + find(tab.begin(), tab.end(), c) - tab.begin() - 1;
		}
		cout << x << "\n";
	}
	return 0;
}
