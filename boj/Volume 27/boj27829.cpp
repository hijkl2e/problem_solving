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
		bool flag = *max_element(A.begin(), A.end()) >= *max_element(B.begin(), B.end());
		cout << (flag ? "Godzilla" : "MechaGodzilla") << "\n";
	}
	return 0;
}
