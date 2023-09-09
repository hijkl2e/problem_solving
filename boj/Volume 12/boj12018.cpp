#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(N, 1);
	for (int i = 0; i < N; ++i) {
		int P{}, L{};
		cin >> P >> L;
		vector<int> B(P);
		for (int j = 0; j < P; ++j) {
			cin >> B[j];
		}
		if (L <= P) {
			sort(B.rbegin(), B.rend());
			A[i] = B[L - 1];
		}
	}
	sort(A.begin(), A.end());
	int ans{};
	for (int i = 0; i < N; ++i) {
		if (M >= A[i]) {
			M -= A[i];
			++ans;
		} else {
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}
