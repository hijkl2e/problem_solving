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
		int maxv1 = *max_element(A.begin(), A.end());
		int maxv2 = *max_element(B.begin(), B.end());
		cout << (maxv1 >= maxv2 ? "S" : "B") << "\n";
	}
	return 0;
}
