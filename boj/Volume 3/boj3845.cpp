#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	double W{};
	while (cin >> N >> M >> W, N) {
		vector<double> A(N);
		vector<double> B(M);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		for (int i = 0; i < M; ++i) {
			cin >> B[i];
		}
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());
		bool yes = true;
		yes &= A.front() < W / 2 + EPS;
		yes &= A.back() > 75 - W / 2 - EPS;
		yes &= B.front() < W / 2 + EPS;
		yes &= B.back() > 100 - W / 2 - EPS;
		for (int i = 0; i < A.size() - 1; ++i) {
			yes &= A[i + 1] - A[i] < W + EPS;
		}
		for (int i = 0; i < B.size() - 1; ++i) {
			yes &= B[i + 1] - B[i] < W + EPS;
		}
		cout << (yes ? "YES" : "NO") << "\n";
	}
	return 0;
}
