#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	int ans{};
	for (char c : S) {
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
