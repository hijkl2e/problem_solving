#include <bits/stdc++.h>

using namespace std;

__int128 bin_to_int(string &s) {
	__int128 ret{};
	for (char c : s) {
		ret = 2 * ret + c - '0';
	}
	return ret;
}

string int_to_bin(__int128 x) {
	string ret;
	if (x == 0) {
		return "0";
	}
	while (x) {
		ret = to_string((int) (x % 2)) + ret;
		x /= 2;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		string s1, s2;
		cin >> s1 >> s2;
		__int128 x = bin_to_int(s1);
		__int128 y = bin_to_int(s2);
		cout << int_to_bin(x + y) << "\n";
	}
	return 0;
}
