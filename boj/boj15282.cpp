#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
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
	sort(A.rbegin(), A.rend());
	sort(B.rbegin(), B.rend());
	int ans{};
	for (int i = 0; i < N && ans < M; ++i) {
		if (A[i] <= B[ans]) {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
