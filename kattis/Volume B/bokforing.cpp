#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, Q{};
	cin >> N >> Q;
	map<int, int> bal;
	int init{};
	while (Q--) {
		string cmd;
		int x{}, y{};
		cin >> cmd >> x;
		if (cmd == "SET") {
			cin >> y;
			bal[x] = y;
		} else if (cmd == "RESTART") {
			bal.clear();
			init = x;
		} else {
			auto it = bal.find(x);
			cout << (it == bal.end() ? init : it->second) << "\n";
		}
	}
	return 0;
}
