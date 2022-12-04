#include <bits/stdc++.h>

using namespace std;

bool valid(int y, int m, int d) {
	if (y < 2000 || m < 1 || m > 12 || d < 1 || d > 31) {
		return false;
	} else if (m == 2) {
		return d < 29 + ((y % 4 == 0 && y % 100) || y % 400 == 0);
	} else {
		return d < 31 + ((m > 7) ^ (m % 2));
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		vector<int> A(8);
		for (int i = 0; i < 8; ++i) {
			char c{};
			cin >> c;
			A[i] = c - '0';
		}
		sort(A.begin(), A.end());
		int Y{}, M{}, D{};
		int cnt{};
		do {
			int y{};
			for (int i = 0; i < 4; ++i) {
				y = 10 * y + A[i];
			}
			int m = 10 * A[4] + A[5];
			int d = 10 * A[6] + A[7];
			if (valid(y, m, d)) {
				if (++cnt == 1) {
					Y = y;
					M = m;
					D = d;
				}
			}
		} while (next_permutation(A.begin(), A.end()));
		cout << setfill('0');
		if (cnt) {
			cout << cnt << " " << setw(2) << D << " " << setw(2) << M << " " << Y << "\n";
		} else {
			cout << "0\n";
		}
	}
	return 0;
}
