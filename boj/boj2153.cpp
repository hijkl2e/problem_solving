#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	int sum{};
	for (char c : S) {
		if (islower(c)) {
			sum += c - 'a' + 1;
		} else {
			sum += c - 'A' + 27;
		}
	}
	bool yes = true;
	for (int i = 2; i * i <= sum; ++i) {
		if (sum % i == 0) {
			yes = false;
			break;
		}
	}
	cout << "It is " << (yes ? "" : "not ") << "a prime word.\n";
	return 0;
}
