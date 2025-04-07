#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	cin.ignore();
	while (T--) {
		string S;
		getline(cin, S);
		istringstream iss(S);
		double x{};
		iss >> x;
		int y = 100 * x + EPS;
		char c{};
		while (iss >> c) {
			if (c == '@') {
				y *= 3;
			} else if (c == '%') {
				y += 500;
			} else {
				y -= 700;
			}
		}
		cout << y / 100 << "." << setfill('0') << setw(2) << y % 100 << "\n";
	}
	return 0;
}
