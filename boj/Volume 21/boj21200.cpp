#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, P{}, S{};
	cin >> N >> P >> S;
	while (S--) {
		int M{};
		cin >> M;
		bool keep = false;
		while (M--) {
			int x{};
			cin >> x;
			keep |= x == P;
		}
		cout << (keep ? "KEEP" : "REMOVE") << "\n";
	}
	return 0;
}
