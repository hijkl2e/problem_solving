#include <bits/stdc++.h>

using namespace std;

int reverse(int x) {
	string s = to_string(x);
	reverse(s.begin(), s.end());
	return stoi(s);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		int x = N + reverse(N);
		cout << (x == reverse(x) ? "YES" : "NO") << "\n";
	}
	return 0;
}
