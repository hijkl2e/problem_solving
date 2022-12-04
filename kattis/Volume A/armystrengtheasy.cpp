#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{}, M{};
		cin >> N >> M;
		vector<int> A(N);
		vector<int> B(M);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		for (int i = 0; i < M; ++i) {
			cin >> B[i];
		}
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());
		cout << (A[N - 1] >= B[M - 1] ? "Godzilla" : "MechaGodzilla") << "\n";
	}
	return 0;
}
