#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	cin.ignore();
	while (T--) {
		string s;
		getline(cin, s);
		istringstream iss(s);
		int x{}, ans{};
		while (iss >> x) {
			ans += x;
		}
		cout << ans << "\n";
	}
	return 0;
}
