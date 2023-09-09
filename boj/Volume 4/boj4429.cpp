#include <bits/stdc++.h>

using namespace std;

int solve(vector<string> &A) {
	static string tab = "23456789TJQKA";
	static vector<int> B(5);
	bool flush = true;
	for (int i = 0; i < 4; ++i) {
		flush &= A[i][1] == A[i + 1][1];
	}
	for (int i = 0; i < 5; ++i) {
		B[i] = tab.find(A[i][0]);
	}
	sort(B.rbegin(), B.rend());
	bool straight = true;
	for (int i = 0; i < 4; ++i) {
		straight &= B[i] == B[i + 1] + 1;
	}
	int ret{};
	if (straight && flush) {
		ret = 8000000 + B[0];
	} else if (B[0] == B[3] || B[1] == B[4]) {
		ret = 7000000 + B[2];
	} else if ((B[0] == B[2] && B[3] == B[4]) || (B[0] == B[1] && B[2] == B[4])) {
		ret = 6000000 + B[2];
	} else if (flush) {
		ret = 5000000;
	} else if (straight) {
		ret = 4000000 + B[0];
	} else if (B[0] == B[2] || B[1] == B[3] || B[2] == B[4]) {
		ret = 3000000 + B[2];
	}
	if (ret == 0 || ret == 5000000) {
		ret = 0;
		int x{};
		for (int i = 0; i < 4; ++i) {
			if (B[i] == B[i + 1]) {
				x |= 3 << i++;
			}
		}
		for (int k = 1; k >= 0; --k) {
			for (int i = 0; i < 5; ++i) {
				if (((x >> i) & 1) == k) {
					ret = 13 * ret + B[i];
					i += k;
				}
			}
		}
		ret += (flush ? 5 : (__builtin_popcount(x) / 2)) * 1000000;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<string> A(5);
	vector<string> B(5);
	while (cin >> A[0]) {
		for (int i = 1; i < 5; ++i) {
			cin >> A[i];
		}
		for (int i = 0; i < 5; ++i) {
			cin >> B[i];
		}
		int x = solve(A);
		int y = solve(B);
		cout << (x > y ? "Black wins" : x < y ? "White wins" : "Tie") << ".\n";
	}
	return 0;
}
