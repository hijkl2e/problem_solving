#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	int cnt1{}, cnt2{}, cnt3{}, cnt4{};
	for (char c : S) {
		if (c == '_') {
			++cnt1;
		} else if (islower(c)) {
			++cnt2;
		} else if (isupper(c)) {
			++cnt3;
		} else {
			++cnt4;
		}
	}
	cout << fixed << setprecision(15);
	cout << cnt1 * 1.0 / S.size() << "\n";
	cout << cnt2 * 1.0 / S.size() << "\n";
	cout << cnt3 * 1.0 / S.size() << "\n";
	cout << cnt4 * 1.0 / S.size() << "\n";
	return 0;
}
