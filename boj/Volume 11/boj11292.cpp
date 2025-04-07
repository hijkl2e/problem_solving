#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	while (cin >> N, N) {
		vector<string> A(N);
		vector<double> B(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i] >> B[i];
		}
		vector<string> C;
		double maxv = B[0];
		for (int i = 0; i < N; ++i) {
			if (maxv < B[i]) {
				maxv = B[i];
				C.clear();
			}
			if (maxv == B[i]) {
				C.push_back(A[i]);
			}
		}
		for (int i = 0; i < C.size(); ++i) {
			cout << C[i] << (i == C.size() - 1 ? "\n" : " ");
		}
	}
	return 0;
}
