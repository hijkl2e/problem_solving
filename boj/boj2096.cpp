#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

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
			D[i] = -INF, E[i] = INF;
			for (int j = -1; j < 2; ++j) {
				if (0 <= i + j && i + j < 3) {
					D[i] = max(D[i], B[i + j]);
					E[i] = min(E[i], C[i + j]);
				}
			}
			D[i] += A[i];
			E[i] += A[i];
		}
		copy(D.begin(), D.end(), B.begin());
		copy(E.begin(), E.end(), C.begin());
	}
	int maxv = *max_element(B.begin(), B.end());
	int minv = *min_element(C.begin(), C.end());
	cout << maxv << " " << minv << "\n";
	return 0;
}
