#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;
	ll ans = stoll(s1 + s2) + stoll(s3 + s4);
	cout << ans << "\n";
	return 0;
}
