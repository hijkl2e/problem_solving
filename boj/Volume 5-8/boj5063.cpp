#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int R{}, E{}, C{};
		cin >> R >> E >> C;
		E -= C;
		if (R < E) {
			cout << "advertise\n";
		} else if (R > E) {
			cout << "do not advertise\n";
		} else {
			cout << "does not matter\n";
		}
	}
	return 0;
}
