#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll bin_to_int(string &s) {
	ll ret{};
	for (int i = 0; i < s.size(); ++i) {
		ret = 2 * ret + (s[i] - '0');
	}
	return ret;
}

string int_to_bin(ll x) {
	string ret;
	while (x) {
		ret += to_string(x % 2);
		x /= 2;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	ll x = bin_to_int(s1);
	ll y = bin_to_int(s2);
	cout << int_to_bin(x * y) << "\n";
	return 0;
}
