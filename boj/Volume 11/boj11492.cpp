#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int M{}, N{};
	cin >> M >> N;
	vector<ll> T(M);
	vector<ll> X(N);
	for (int i = 0; i < M; ++i) {
		cin >> T[i];
	}
	for (int i = 1; i < M; ++i) {
		T[i] -= T[0];
	}
	for (int i = 0; i < N; ++i) {
		cin >> X[i];
	}
	vector<ll> A;
	for (int i = 0; i + M <= N; ++i) {
		bool yes = true;
		for (int j = 2; j < M; ++j) {
			__int128 x = X[i + 1] - X[i];
			yes &= x * T[j] % T[1] == 0 && x * T[j] / T[1] == X[i + j] - X[i];
		}
		if (yes) {
			A.push_back(X[i + 1] - X[i]);
		}
	}
	sort(A.begin(), A.end());
	A.resize(unique(A.begin(), A.end()) - A.begin());
	cout << A.size() << "\n";
	for (int i = 0; i < A.size(); ++i) {
		cout << A[i] << (i == A.size() - 1 ? "" : " ");
	}
	cout << "\n";
	return 0;
}
