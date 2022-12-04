#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	double x{};
	int lo{}, hi{};
	cin >> x >> lo >> hi;
	int mink = -1, maxk = -1;
	for (int i = 0; i < 10; ++i) {
		int y = ceil(x);
		if (lo <= y && y <= hi) {
			if (mink == -1) {
				mink = i;
			}
			maxk = i;
		}
		x = 10 * sqrt(x);
	}
	if (mink == -1) {
		cout << "impossible\n";
	} else if (hi == 100) {
		cout << mink << " inf\n";
	} else {
		cout << mink << " " << maxk << "\n";
	}
	return 0;
}
