#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int D{};
	cin >> D;
	int n1{}, n2{};
	for (int i = 1; i < 100001; ++i) {
		for (int j = i - 1; j >= 0; --j) {
			int d = i * i - j * j;
			if (d == D) {
				n1 = j, n2 = i;
				i = 1e9;
				break;
			} else if (d > D) {
				break;
			}
		}
	}
	if (n2) {
		cout << n1 << " " << n2 << "\n";
	} else {
		cout << "impossible\n";
	}
	return 0;
}
