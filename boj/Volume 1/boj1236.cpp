#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	deque<bool> B(N);
	deque<bool> C(M);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (A[i][j] == 'X') {
				B[i] = C[j] = true;
			}
		}
	}
	int ans = max(count(B.begin(), B.end(), false), count(C.begin(), C.end(), false));
	cout << ans << "\n";
	return 0;
}
