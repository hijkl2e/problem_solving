#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	for (int tc = 1; cin >> s; ++tc) {
		map<string, int> A, B;
		string cmd;
		while (cin >> cmd, cmd != "CLOSE") {
			int x{};
			cin >> s >> x;
			if (cmd == "ENTER") {
				A[s] = x;
			} else {
				B[s] += x - A[s];
			}
		}
		if (tc > 1) {
			cout << "\n";
		}
		cout << "Day " << tc << "\n";
		for (auto &p : B) {
			cout << p.first << " $" << p.second / 10 << "." << p.second % 10 << "0\n";
		}
	}
	return 0;
}
