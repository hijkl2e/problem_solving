#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int M{};
	cin >> M;
	vector<int> B(M);
	for (int i = 0; i < M; ++i) {
		cin >> B[i];
	}
	sort(A.rbegin(), A.rend());
	sort(B.rbegin(), B.rend());
	if (A[0] < B[0]) {
		cout << "-1\n";
		return 0;
	}
	vector<int> C(N);
	for (int i = 0; i < M; ++i) {
		int p{};
		for (int j = 0; j < N; ++j) {
			if (A[j] < B[i]) {
				break;
			} else if (C[p] > C[j]) {
				p = j;
			}
		}
		++C[p];
	}
	int ans = *max_element(C.begin(), C.end());
	cout << ans << "\n";
	return 0;
}
