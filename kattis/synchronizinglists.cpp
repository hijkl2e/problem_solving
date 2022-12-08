#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	for (int tc = 0; cin >> N, N; ++tc) {
		vector<int> A(N);
		vector<int> B(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		for (int i = 0; i < N; ++i) {
			cin >> B[i];
		}
		vector<int> C(A.begin(), A.end());
		sort(B.begin(), B.end());
		sort(C.begin(), C.end());
		if (tc) {
			cout << "\n";
		}
		for (int i = 0; i < N; ++i) {
			cout << B[lower_bound(C.begin(), C.end(), A[i]) - C.begin()] << "\n";
		}
	}
	return 0;
}
