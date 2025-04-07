#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int K{}, N{};
	cin >> K >> N;
	--K;
	int rem = 210;
	while (N--) {
		int t{};
		char z{};
		cin >> t >> z;
		if (rem < t) {
			break;
		}
		rem -= t;
		if (z == 'T') {
			K = (K + 1) % 8;
		}
	}
	cout << K + 1 << "\n";
	return 0;
}
