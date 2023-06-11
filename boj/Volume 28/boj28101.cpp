#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<vector<ll>> A(N, vector<ll>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
		}
	}
	bool yes = true;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (A[0][0] * A[i][j] != A[i][0] * A[0][j]) {
				yes = false;
			}
		}
	}
	if (!yes) {
		cout << "-1\n";
		return 0;
	}
	vector<int> B(N);
	vector<int> C(N);
	for (int i = 0; i < N; ++i) {
		B[i] = A[0][i];
		C[i] = A[i][0];
	}
	sort(B.begin(), B.end());
	sort(C.begin(), C.end());
	B.resize(unique(B.begin(), B.end()) - B.begin());
	C.resize(unique(C.begin(), C.end()) - C.begin());
	vector<ii> D;
	for (int i = 0; i < B.size(); ++i) {
		for (int j = 0; j < C.size(); ++j) {
			int g = gcd(B[i], C[j]);
			D.push_back({B[i] / g, C[j] / g});
		}
	}
	sort(D.begin(), D.end());
	int maxv{};
	for (int i = 0, j = 1; i < D.size(); i = j++) {
		while (j < D.size() && D[i] == D[j]) {
			++j;
		}
		maxv = max(maxv, j - i);
	}
	int ans = B.size() + C.size() - maxv;
	cout << ans << "\n";
	return 0;
}
