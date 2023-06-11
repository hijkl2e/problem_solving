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
	vector<int> B(7);
	for (int i = 0; i < N; ++i) {
		++B[A[i]];
	}
	int ans{};
	for (int i = 6; i > 0; --i) {
		if (B[i] == 1) {
			ans = find(A.begin(), A.end(), i) - A.begin() + 1;
			break;
		}
	}
	if (ans) {
		cout << ans << "\n";
	} else {
		cout << "none\n";
	}
	return 0;
}
