#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<int> B(M);
	for (int i = 0; i < M; ++i) {
		cin >> B[i];
	}
	vector<int> C(N);
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			if (A[j] <= B[i]) {
				++C[j];
				break;
			}
		}
	}
	int ans = max_element(C.begin(), C.end()) - C.begin() + 1;
	cout << ans << "\n";
	return 0;
}
