#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		vector<int> A(N + 1);
		for (int i = 1; i <= N; ++i) {
			cin >> A[i];
		}
		vector<int> B(N + 1, -1);
		int x = 1;
		for (int i = 0; B[x] == -1; ++i) {
			B[x] = i;
			x = A[x];
		}
		cout << (B[N] == -1 ? 0 : B[N]) << "\n";
	}
	return 0;
}
