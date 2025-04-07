#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s1, s2;
	cin >> s1 >> s2;
	ll ans = accumulate(s1.begin(), s1.end(), 0LL) - s1.size() * '0';
	ans *= accumulate(s2.begin(), s2.end(), 0LL) - s2.size() * '0';
	cout << ans << "\n";
	return 0;
}
