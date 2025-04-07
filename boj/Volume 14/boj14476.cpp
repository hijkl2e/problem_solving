#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N + 2);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	vector<int> B(N + 2);
	vector<int> C(N + 2);
	for (int i = 1; i <= N; ++i) {
		B[i] = gcd(B[i - 1], A[i]);
	}
	for (int i = N; i > 0; --i) {
		C[i] = gcd(C[i + 1], A[i]);
	}
	int maxv = -1, p{};
	for (int i = 1; i <= N; ++i) {
		int g = gcd(B[i - 1], C[i + 1]);
		if (A[i] % g && maxv < g) {
			maxv = g, p = i;
		}
	}
	if (maxv == -1) {
		cout << "-1\n";
	} else {
		cout << maxv << " " << A[p] << "\n";
	}
	return 0;
}
