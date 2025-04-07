#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	while (getline(cin, s), s != "END") {
		int x = stod(s) * 1e6 + EPS;
		int y = x;
		bool yes = true;
		do {
			y *= 3;
			if (y >= 2000000) {
				y -= 2000000;
			} else if (y >= 1000000) {
				yes = false;
				break;
			}
		} while (x != y);
		cout << (yes ? "MEMBER" : "NON-MEMBER") << "\n";
	}
	return 0;
}
