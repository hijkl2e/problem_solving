#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	if (T % 10) {
		cout << "-1\n";
	} else {
		T /= 10;
		cout << T / 30 << " " << T % 30 / 6 << " " << T % 6 << "\n";
	}
	return 0;
}
