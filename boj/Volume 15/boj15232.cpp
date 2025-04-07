#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int R{}, C{};
	cin >> R >> C;
	for (int i = 0; i < R; ++i) {
		cout << string(C, '*') << "\n";
	}
	return 0;
}
