#include <bits/stdc++.h>

using namespace std;

string solve(int x) {
	string ret;
	for (int i = 0; i < 4; ++i) {
		char c = x % 26 + 'a';
		ret += c;
		x /= 26;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int A{}, B{};
	cin >> A >> B;
	for (int i = 0; i < B; ++i) {
		cout << solve(i) << (i == B - 1 ? "\n" : " ");
	}
	return 0;
}
