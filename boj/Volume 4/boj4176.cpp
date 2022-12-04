#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string x;
	while (getline(cin, x), x != "END") {
		int ans = 1;
		while (x != "1") {
			x = to_string(x.size());
			++ans;
		}
		cout << ans << "\n";
	}
	return 0;
}
