#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, x{}, y{};
	cin >> N >> x >> y;
	vector<int> A(2 * N);
	for (int i = 1; i < A.size(); ++i) {
		A[i] = 2 * N - abs(i - N) - 1;
	}
	string S = string(N - 1, 'D');
	for (int i = 2; i < 2 * (N - 1); ++i) {
		if (i % 2) {
			S += A[i - 1] < A[i] ? 'Z' : 'C';
			S += string(A[i] - 2, 'D');
		} else {
			S += A[i - 1] < A[i] ? 'C' : 'Z';
			S += string(A[i] - 2, 'A');
		}
	}
	S += N == 2 ? "CZ" : "ZZ";
	for (int i = 0; i < N - 1; ++i) {
		S += "QZ";
	}
	S += string(N - 1, 'Q');
	S += string(N - 1, 'E');
	int p{};
	if (x == 1) {
		p = y - 1;
	} else if (y == 1) {
		p = 3 * N * (N - 1) - x + 2;
	} else if (x < 2 * (N - 1)) {
		p = N - 1;
		for (int i = 2; i < x; ++i) {
			p += A[i] - 1;
		}
		p += x % 2 ? (y - 1) : (A[x] - y + 1);
	} else {
		p = 3 * N * (N - 1) - x - 2 * y + 4;
	}
	rotate(S.begin(), S.begin() + p, S.end());
	cout << S << "\n";
	return 0;
}
