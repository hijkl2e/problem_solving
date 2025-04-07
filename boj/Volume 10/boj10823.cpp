#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s, t;
	while (getline(cin, s)) {
		t += s;
	}
	istringstream iss(t);
	int x{}, ans{};
	char c{};
	while (iss >> x) {
		ans += x;
		iss >> c;
	}
	cout << ans << "\n";
	return 0;
}
