#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	int sum{};
	bool flag{};
	for (char c : S) {
		sum += c - '0';
		flag |= c == '0';
	}
	if (sum % 3 == 0 && flag) {
		sort(S.rbegin(), S.rend());
		cout << S << "\n";
	} else {
		cout << "-1\n";
	}
	return 0;
}
