#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;

ull func(string S, ull N, ull L) {
	if (S == "O(N)") {
		return N;
	} else if (S == "O(N^2)") {
		return N * N;
	} else if (S == "O(N^3)") {
		return N * N * N;
	}
	ull res = 1;
	if (S == "O(2^N)") {
		while (N-- && res <= L) {
			res *= 2;
		}
	} else {
		while (N && res <= L) {
			res *= N--;
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int C{};
	cin >> C;
	while (C--) {
		string S;
		ull N{}, T{}, L{};
		cin >> S >> N >> T >> L;
		L *= 100000000;
		cout << (T * func(S, N, L) <= L ? "May Pass." : "TLE!") << "\n";
	}
	return 0;
}
