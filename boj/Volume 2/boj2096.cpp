#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(3);
	vector<int> B(3);
	vector<int> C(3);
	vector<int> D(3);
	vector<int> E(3);
	while (N--) {
		for (int i = 0; i < 3; ++i) {
			cin >> A[i];
		}
		for (int i = 0; i < 3; ++i) {
			D[0] = max(B[0], B[1]) + A[0];
			D[1] = max({B[0], B[1], B[2]}) + A[1];
			D[2] = max(B[1], B[2]) + A[2];
			E[0] = min(C[0], C[1]) + A[0];
			E[1] = min({C[0], C[1], C[2]}) + A[1];
			E[2] = min(C[1], C[2]) + A[2];
		}
		copy(D.begin(), D.end(), B.begin());
		copy(E.begin(), E.end(), C.begin());
	}
	int maxv = max({B[0], B[1], B[2]});
	int minv = min({C[0], C[1], C[2]});
	cout << maxv << " " << minv << "\n";
	return 0;
}
