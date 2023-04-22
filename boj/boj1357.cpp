#include <bits/stdc++.h>

using namespace std;

int rev(int x) {
	string s = to_string(x);
	reverse(s.begin(), s.end());
	return stoi(s);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int x{}, y{};
	cin >> x >> y;
	int ans = rev(rev(x) + rev(y));
	cout << ans << "\n";
	return 0;
}
