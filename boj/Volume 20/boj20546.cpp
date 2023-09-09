#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(14);
	for (int i = 0; i < 14; ++i) {
		cin >> A[i];
	}
	int x1{}, y1{}, x2{}, y2{};
	x1 = N;
	for (int i = 0; i < 14; ++i) {
		int k = x1 / A[i];
		x1 -= k * A[i];
		y1 += k;
	}
	x2 = N;
	for (int i = 3; i < 14; ++i) {
		if (A[i - 3] < A[i - 2] && A[i - 2] < A[i - 1] && A[i - 1] < A[i]) {
			x2 += y2 * A[i];
			y2 = 0;
		} else if (A[i - 3] > A[i - 2] && A[i - 2] > A[i - 1] && A[i - 1] > A[i]) {
			int k = x2 / A[i];
			x2 -= k * A[i];
			y2 += k;
		}
	}
	x1 += y1 * A[13];
	x2 += y2 * A[13];
	cout << (x1 > x2 ? "BNP" : x1 < x2 ? "TIMING" : "SAMESAME") << "\n";
	return 0;
}
