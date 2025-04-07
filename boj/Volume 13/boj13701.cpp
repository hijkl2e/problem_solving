#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	bitset<33554432> B;
	int x{};
	bool first = true;
	while (cin >> x) {
		if (B[x]) {
			continue;
		}
		B[x] = true;
		cout << (first ? "" : " ") << x;
		first = false;
	}
	cout << "\n";
	return 0;
}
