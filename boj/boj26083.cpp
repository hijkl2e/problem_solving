#include <bits/stdc++.h>

using namespace std;

bool solve(int A, int B, int C) {
	if (B == 0 || B > 12 || C == 0 || C > 31) {
		return false;
	} else if (B == 2) {
		return C < 29 + (A % 4 == 0);
	} else {
		return C < 31 + ((B > 7) ^ (B % 2));
	}
}

int solve(int y1, int m1, int d1, int y2, int m2, int d2) {
	return solve(y2, m2, d2) ? (y1 < y2 || (y1 == y2 && (m1 < m2 || (m1 == m2 && d1 <= d2)))) + 1 : 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int Y{}, M{}, D{};
	cin >> Y >> M >> D;
	int N{};
	cin >> N;
	while (N--) {
		int A{}, B{}, C{};
		cin >> A >> B >> C;
		int res{};
		res |= solve(Y, M, D, A, B, C);
		res |= solve(Y, M, D, C, B, A);
		res |= solve(Y, M, D, C, A, B);
		cout << (res ? res % 2 == 0 ? "safe" : "unsafe" : "invalid") << "\n";
	}
	return 0;
}
