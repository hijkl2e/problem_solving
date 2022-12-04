#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int x{};
	while (cin >> x, x) {
		string S, P, C;
		cin >> S >> P >> C;
		int N = C.size();
		int d = N  * sqrt(N) + x + EPS;
		d %= N;
		string M;
		M.resize(N);
		M[d] = P[S.find(C[d])];
		int i = d;
		for (int i = (d + N - 1) % N; i != d; i = (i + N - 1) % N) {
			M[i] = P[S.find(C[i]) ^ S.find(M[(i + 1) % N])];
		}
		cout << M << "\n";
	}
	return 0;
}
