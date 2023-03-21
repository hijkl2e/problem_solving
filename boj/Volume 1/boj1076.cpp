#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	map<string, int> c2v{
		{"black", 0}, {"brown", 1}, {"red", 2}, {"orange", 3}, {"yellow", 4},
		{"green", 5}, {"blue", 6}, {"violet", 7}, {"grey", 8}, {"white", 9}
	};
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	ll ans = 10 * c2v[s1] + c2v[s2];
	for (int i = c2v[s3]; i > 0; --i) {
		ans *= 10;
	}
	cout << ans << "\n";
	return 0;
}
